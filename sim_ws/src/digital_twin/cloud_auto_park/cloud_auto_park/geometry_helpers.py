import numpy as np
from typing import Tuple, List
import math
import time

## DISCLAIMER: THIS CODE IS LLM-GENERATED (GEMINI FLASH EXTENDED 3.5). USE WITH PRECAUTION.

class OrientedBoundingBox:
    def __init__(self, centroid_x_m, centroid_y_m, length_m, width_m, heading_rad):
        self.centroid_x_m = centroid_x_m
        self.centroid_y_m = centroid_y_m
        self.length_m = length_m
        self.width_m = width_m
        self.heading_rad = heading_rad
        
def support_obb(obb: OrientedBoundingBox, direction: np.ndarray) -> np.ndarray:
    """
    Computes the support point of an OrientedBoundingBox in a given direction.
    - length_m is assumed to run along the heading vector (local X-axis).
    - width_m is assumed to run perpendicular to the heading vector (local Y-axis).
    """
    center = np.array([obb.centroid_x_m, obb.centroid_y_m])
    half_l = obb.length_m / 2.0
    half_w = obb.width_m / 2.0
    
    # Compute the local coordinate system axes from heading_rad
    cos_h = np.cos(obb.heading_rad)
    sin_h = np.sin(obb.heading_rad)
    ux = np.array([cos_h, sin_h])   # Heading axis (longitudinal)
    uy = np.array([-sin_h, cos_h])  # Lateral axis (perpendicular)
    
    proj_x = np.dot(direction, ux)
    proj_y = np.dot(direction, uy)
    
    return center + np.sign(proj_x) * half_l * ux + np.sign(proj_y) * half_w * uy


def support_minkowski(obb_a: OrientedBoundingBox, 
                      obb_b: OrientedBoundingBox, 
                      direction: np.ndarray) -> np.ndarray:
    """
    Computes the support point of the Minkowski Difference (A - B) in direction d.
    """
    return support_obb(obb_a, direction) - support_obb(obb_b, -direction)


def closest_point_on_segment(a: np.ndarray, b: np.ndarray) -> Tuple[np.ndarray, List[np.ndarray]]:
    """
    Finds the point closest to the origin on line segment AB.
    """
    ab = b - a
    ab_len_sq = np.dot(ab, ab)
    if ab_len_sq < 1e-9:
        return a, [a]
    
    t = np.dot(-a, ab) / ab_len_sq
    if t <= 0:
        return a, [a]
    elif t >= 1:
        return b, [b]
    else:
        return a + t * ab, [a, b]


def closest_point_on_triangle(a: np.ndarray, b: np.ndarray, c: np.ndarray) -> Tuple[np.ndarray, List[np.ndarray], bool]:
    """
    Finds the point closest to the origin on the triangle ABC.
    Identifies if the origin is enclosed (collision).
    """
    p_ab, simplex_ab = closest_point_on_segment(a, b)
    dist_ab = np.dot(p_ab, p_ab)
    
    p_bc, simplex_bc = closest_point_on_segment(b, c)
    dist_bc = np.dot(p_bc, p_bc)
    
    p_ca, simplex_ca = closest_point_on_segment(c, a)
    dist_ca = np.dot(p_ca, p_ca)
    
    def cross_2d(u, v):
        return u[0] * v[1] - u[1] * v[0]
    
    cross_ab = cross_2d(b - a, -a)
    cross_bc = cross_2d(c - b, -b)
    cross_ca = cross_2d(a - c, -c)
    
    if (cross_ab > 0 and cross_bc > 0 and cross_ca > 0) or \
       (cross_ab < 0 and cross_bc < 0 and cross_ca < 0):
        return np.array([0.0, 0.0]), [a, b, c], True
    
    min_dist = dist_ab
    best_p = p_ab
    best_simplex = simplex_ab
    
    if dist_bc < min_dist:
        min_dist = dist_bc
        best_p = p_bc
        best_simplex = simplex_bc
        
    if dist_ca < min_dist:
        best_p = p_ca
        best_simplex = simplex_ca
        
    return best_p, best_simplex, False


def gjk_distance_2d(obb_a: OrientedBoundingBox, 
                    obb_b: OrientedBoundingBox, 
                    max_iterations: int = 50, 
                    tolerance: float = 1e-6) -> Tuple[float, bool]:
    """
    Computes the minimum distance and collision status between two OrientedBoundingBox instances.
    Returns:
        distance (float): Minimum Euclidean distance between boxes (0.0 if colliding).
        colliding (bool): True if boxes intersect, False otherwise.
    """
    center_a = np.array([obb_a.centroid_x_m, obb_a.centroid_y_m])
    center_b = np.array([obb_b.centroid_x_m, obb_b.centroid_y_m])
    
    d = center_b - center_a
    if np.linalg.norm(d) < 1e-9:
        d = np.array([1.0, 0.0])
        
    s0 = support_minkowski(obb_a, obb_b, d)
    simplex = [s0]
    v = s0 
    
    for _ in range(max_iterations):
        d = -v
        d_norm = np.linalg.norm(d)
        if d_norm < tolerance:
            return 0.0, True
        
        d_unit = d / d_norm
        p = support_minkowski(obb_a, obb_b, d_unit)
        
        proj_p = np.dot(p, d_unit)
        proj_v = np.dot(v, d_unit)
        
        if proj_p - proj_v < tolerance:
            return np.linalg.norm(v), False
        
        simplex.append(p)
        
        if len(simplex) == 2:
            v, simplex = closest_point_on_segment(simplex[0], simplex[1])
        elif len(simplex) == 3:
            v, simplex, is_colliding = closest_point_on_triangle(simplex[0], simplex[1], simplex[2])
            if is_colliding:
                return 0.0, True
                
    return np.linalg.norm(v), False


def sat_obb_collision(obb_a: OrientedBoundingBox, obb_b: OrientedBoundingBox) -> Tuple[bool, float]:
    """
    Evaluates collision and measures distance metrics using the Separating Axis Theorem (SAT).
    
    Returns:
        colliding (bool): True if the boxes overlap, False otherwise.
        metric (float): If colliding, returns the exact Penetration Depth (positive).
                        If separated, returns a conservative Separation Distance (positive).
    """
    # 1. Gather Centers
    c_a = np.array([obb_a.centroid_x_m, obb_a.centroid_y_m])
    c_b = np.array([obb_b.centroid_x_m, obb_b.centroid_y_m])
    
    # 2. Compute Local Coordinate Axes from Heading
    cos_a, sin_a = np.cos(obb_a.heading_rad), np.sin(obb_a.heading_rad)
    axes_a = [np.array([cos_a, sin_a]), np.array([-sin_a, cos_a])] # [Local X (length), Local Y (width)]
    
    cos_b, sin_b = np.cos(obb_b.heading_rad), np.sin(obb_b.heading_rad)
    axes_b = [np.array([cos_b, sin_b]), np.array([-sin_b, cos_b])] # [Local X (length), Local Y (width)]
    
    # The 4 separating axes we must test
    candidate_axes = axes_a + axes_b
    
    min_overlap = float('inf')
    max_gap = -float('inf')
    colliding = True
    
    for axis in candidate_axes:
        # Normalize the test axis (precautionary, though heading unit vectors are already unit length)
        axis_norm = axis / np.linalg.norm(axis)
        
        # Project centers onto the axis
        proj_ca = np.dot(c_a, axis_norm)
        proj_cb = np.dot(c_b, axis_norm)
        
        # Project half-extents to find the radius of projection for both boxes
        r_a = (obb_a.length_m / 2.0) * abs(np.dot(axes_a[0], axis_norm)) + \
              (obb_a.width_m / 2.0) * abs(np.dot(axes_a[1], axis_norm))
              
        r_b = (obb_b.length_m / 2.0) * abs(np.dot(axes_b[0], axis_norm)) + \
              (obb_b.width_m / 2.0) * abs(np.dot(axes_b[1], axis_norm))
        
        # Calculate overlap projection properties
        dist_proj = abs(proj_cb - proj_ca)
        overlap = (r_a + r_b) - dist_proj
        
        if overlap < 0:
            # A gap was found! They are separated.
            colliding = False
            gap = -overlap
            if gap > max_gap:
                max_gap = gap
        else:
            # Overlap exists on this axis
            if overlap < min_overlap:
                min_overlap = overlap
                
    if colliding:
        # If they overlap on all axes, return collision status and the minimum penetration depth
        return True, min_overlap
    else:
        # If any gap was found, return separation status and the maximum gap (conservative distance)
        return False, max_gap
    
from typing import Tuple

def get_exact_distance_or_overlap(obb_a: OrientedBoundingBox, obb_b: OrientedBoundingBox) -> Tuple[bool, float]:
    """
    Computes the exact minimum distance if separated, or the exact overlap depth if colliding.
    
    Returns:
        colliding (bool): True if overlapping, False if separated.
        metric (float): If colliding, the exact penetration depth (positive).
                        If separated, the exact minimum Euclidean distance (positive).
    """
    # 1. Use GJK to find the exact minimum separation distance
    gjk_dist, is_colliding = gjk_distance_2d(obb_a, obb_b)
    
    if not is_colliding:
        # GJK successfully found the exact diagonal minimum distance!
        return False, gjk_dist
        
    # 2. If colliding, use SAT to find the exact overlap (penetration depth)
    _, penetration_depth = sat_obb_collision(obb_a, obb_b)
    return True, -1 * penetration_depth


def run_hybrid_test_suite():
    tests = [
        {
            "name": "1. Simple Axis-Aligned Separation",
            "obb_a": OrientedBoundingBox(centroid_x_m=0.0, centroid_y_m=0.0, length_m=2.0, width_m=2.0, heading_rad=0.0),
            "obb_b": OrientedBoundingBox(centroid_x_m=4.0, centroid_y_m=0.0, length_m=2.0, width_m=2.0, heading_rad=0.0),
            "expected_collision": False,
            "expected_val": 2.0,
            "desc": "Separated along the X-axis. Expected distance: 4.0 - 1.0 (half A) - 1.0 (half B) = 2.0 m."
        },
        {
            "name": "2. Diagonal Corner-to-Corner Separation",
            "obb_a": OrientedBoundingBox(centroid_x_m=0.0, centroid_y_m=0.0, length_m=2.0, width_m=2.0, heading_rad=0.0),
            "obb_b": OrientedBoundingBox(centroid_x_m=3.0, centroid_y_m=3.0, length_m=2.0, width_m=2.0, heading_rad=0.0),
            "expected_collision": False,
            "expected_val": math.sqrt(2.0), # ~1.4142 m
            "desc": "Tests true Euclidean diagonal distance. Closest points are corners (1, 1) and (2, 2)."
        },
        {
            "name": "3. Simple Axis-Aligned Overlap",
            "obb_a": OrientedBoundingBox(centroid_x_m=0.0, centroid_y_m=0.0, length_m=2.0, width_m=2.0, heading_rad=0.0),
            "obb_b": OrientedBoundingBox(centroid_x_m=1.2, centroid_y_m=0.0, length_m=2.0, width_m=2.0, heading_rad=0.0),
            "expected_collision": True,
            "expected_val": 0.8,
            "desc": "Overlap along the X-axis. Max half-extents sum is 2.0 m. Overlap = 2.0 - 1.2 = 0.8 m."
        },
        {
            "name": "4. Full Containment",
            "obb_a": OrientedBoundingBox(centroid_x_m=0.0, centroid_y_m=0.0, length_m=4.0, width_m=4.0, heading_rad=0.0),
            "obb_b": OrientedBoundingBox(centroid_x_m=0.0, centroid_y_m=0.0, length_m=1.0, width_m=1.0, heading_rad=math.radians(30)),
            "expected_collision": True,
            "expected_val": 2.6830127,
            "desc": "A small box is fully contained inside a larger box. The minimum penetration to push it out is evaluated."
        },
        {
            "name": "5. Complex Rotated Overlap",
            "obb_a": OrientedBoundingBox(centroid_x_m=0.0, centroid_y_m=0.0, length_m=3.0, width_m=1.5, heading_rad=math.radians(10)),
            "obb_b": OrientedBoundingBox(centroid_x_m=2.0, centroid_y_m=1.0, length_m=2.0, width_m=1.0, heading_rad=math.radians(45)),
            "expected_collision": True,
            "expected_val": 0.462677,
            "desc": "Real-world scenario with two rotated vehicles clipping edges slightly."
        }
    ]

    print("=" * 70)
    print(f"{'HYBRID GJK + SAT TEST SUITE':^70}")
    print("=" * 70)
    
    passed = 0
    for test in tests:
        name = test["name"]
        obb_a = test["obb_a"]
        obb_b = test["obb_b"]
        
        # Execute hybrid logic
        s = time.time()
        is_colliding, metric = get_exact_distance_or_overlap(obb_a, obb_b)
        print(f'elapsed: t = {(time.time() - s):.6f}')
        
        # Evaluate results
        col_match = (is_colliding == test["expected_collision"])
        val_match = math.isclose(metric, test["expected_val"], rel_tol=1e-5)
        
        status = "PASS" if (col_match and val_match) else "FAIL"
        if status == "PASS":
            passed += 1
            
        print(f"\n[ {status} ] {name}")
        print(f"  Description: {test['desc']}")
        print(f"  Expected   : Colliding={test['expected_collision']}, Metric={test['expected_val']:.6f}")
        print(f"  Calculated : Colliding={is_colliding}, Metric={metric:.6f}")
        
    print("\n" + "=" * 70)
    print(f"Results: {passed}/{len(tests)} Tests Passed")
    print("=" * 70)

# Run tests
if __name__ == "__main__":
    run_hybrid_test_suite()

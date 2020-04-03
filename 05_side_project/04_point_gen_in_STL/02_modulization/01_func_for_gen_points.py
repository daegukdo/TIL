def select_random_vertex_index(point40_on_STL, vertex_data):
    """
    input data structure
    points = [[x0, y0, z0], ... [xn, yn, zn]]
    vertex_data = [[[px00, py00, pz00], [px01, py01, pz01], [px02, py02, pz02]],
                    ...,
                   [[pxm0, pym0, pzm0], [pxm1, pym1, pzm1], [pxm2, pym2, pzm2]]]
                   
    output data structure
    selected_index = [i0, i1, ... in]
    """
    
    vertex_group                  = []

    for i in range(len(point40_on_STL)):
        temp                      = []
        for j in range(len(vertex_data)):
            if point40_on_STL[i] in vertex_data[j]:
                temp.append(j)
        vertex_group.append(temp)

    vertex_selected_index         = []

    for i in range(len(vertex_group)):
        randomIndex               = random.choice(vertex_group[i])
        vertex_selected_index.append(randomIndex)
        
    return vertex_selected_index, vertex_group

def random_vector(length = 1):
    """
    make vector that have length in sphere
    
    input data structure
    vector length = int
    
    output data structure
    vector = [vx, vy, vz]
    """
    
    rand_i, rand_j = np.random.rand(2)            # Two independent random numbers from a uniform distribution in the range (0, 1)
    theta          = 2 * np.pi * rand_i           # Spherical coordinate theta
    phi            = np.arccos(2 * rand_j - 1)    # Spherical coordinate phi, corrected for distribution bias
    x              = np.cos(theta) * np.sin(phi)  # Cartesian coordinate x
    y              = np.sin(theta) * np.sin(phi)  # Cartesian coordinate y
    z              = np.cos(phi)                  # Cartesian coordinate z
    vector         = [x*math.sqrt(length), y*math.sqrt(length), z*math.sqrt(length)]

    return vector

def add_mm_error_to_point(point, error = 20):
    """
    input data structure
    point = [x, y, z] # x, y, z unit = mm
    
    output data structure
    point_added_error = [x', y', z']
    """
    
    point_added_error      = point.copy()
    
    xyz_error              = random_vector(error)

    point_added_error[0]   += xyz_error[0]
    point_added_error[1]   += xyz_error[1]
    point_added_error[2]   += xyz_error[2]
    
    return point_added_error

def find_projection_point_in_plane_3D(point, plane, norm_vect):
    """
    input data structure
    point = [x, y, z]
    plane = [a, b, c, d] # plane eq. = ax + by + cz + d = 0
    norm_vect = [i, j, k]
    
    output data structure
    True -> projected_point = [x', y', z']
    False -> value of diff. with plane = float(d)
    """
    
    plane_ABC_sqrt       = math.sqrt(plane[0]*plane[0] + plane[1]*plane[1] + plane[2]*plane[2])
    dist                 = (plane[3] + plane[0] * point[0] + plane[1] * point[1] + plane[2] * point[2]) / plane_ABC_sqrt
    # print(dist)
    projected_point      = point - dist * norm_vect
    
    on_the_plane_value   = is_including_point(plane, projected_point)
    
    if on_the_plane_value:
        pass
    else:
        print(projected_point)
        # print(on_the_plane_value)
     
    return projected_point 

def is_including_point(plane, point):
    """
    input data structure
    point = [x, y, z]
    plane = [a, b, c, d] # plane eq. = ax + by + cz + d = 0
    
    output data structure
    is point included in plane = bool
    """
    
    a                 = plane[0]
    b                 = plane[1]
    c                 = plane[2]
    d                 = plane[3]
    x                 = point[0]
    y                 = point[1]
    z                 = point[2]
    
    included_value    = a*x + b*y + c*z + d
    # print(included_value)
    
    if included_value < 0.00001:
        return True
    else:
        return False
    
def cal_points40_with_error_on_plane(point40_on_STL, plane_selected, vector_selected):
    """
    input data structure
    points = [[xr0, yr0, zr0], ... [xrn, yrn, zrn]]
    plane_data = [[a0, b0, c0, d0], [a1, b1, c1, d1], ... [am, bm, cm, dm]]
    vector_data = [[vx0, vy0, vz0], ... [vxn, vyn, vzn]]
    
    output data structure (closet points in trg_points from ref_points)
    points_on_plane = [[xpr0, ypr0, zpr0], ... [xprn, yprn, zprn]]
    """
    
    points40_with_error_on_plane    = []

    data_point_40_slt               = point40_on_STL.copy()

    for i in range(len(data_point_40_slt)):        
        _point_added_error          = add_mm_error_to_point(data_point_40_slt[i])
        _point_on_plane             = find_projection_point_in_plane_3D(_point_added_error, 
                                                                        plane_selected[i],
                                                                        vector_selected[i])
        
        if np.isnan(np.sum(_point_on_plane)):
            points40_with_error_on_plane.append(data_point_40_slt[i])
        else:
            points40_with_error_on_plane.append(_point_on_plane)
            
    return points40_with_error_on_plane

def get_dist_btw_2_3Dpoints(point1, point2):
    """
    input data structure
    point1 = [x1, y1, z1]
    point2 = [x2, y2, z2]
    
    output data structure
    distance
    """
    
    sum        = 0
    for i in range(3):
        sum    = sum + (point1[i] - point2[i])**2
    return math.sqrt(sum)

def get_closet_points(ref_points, trg_points):
    """
    input data structure
    ref_points = [[xr0, yr0, zr0], ... [xrn, yrn, zrn]]
    trg_points = [[xt0, yt0, zt0], ... [xtm, ytm, ztm]]
    
    output data structure (closet points in trg_points from ref_points)
    closet_points = [[xc0, yc0, zc0], ... [xcn, ycn, zcn]]
    """
    
    tree                         = KDTree(trg_points)
    nearest_dist, nearest_ind    = tree.query(ref_points, k=2)
    
    nearest_index                = nearest_ind[:,1]
    closet_points                = []
    
    for i in range(len(nearest_index)):
        closet_points.append(trg_points[nearest_index[i]])
        
    return closet_points
    
def get_data_with_index(index_data, some_data):
    """
    input data structure
    index_data = [i0, i1, ... in]
    some_data = plane_data or vertex_data or vector_data
    plane_data = [[a0, b0, c0, d0], [a1, b1, c1, d1], ... [am, bm, cm, dm]]
    vertex_data = [[[px00, py00, pz00], [px01, py01, pz01], [px02, py02, pz02]],
                    ...,
                   [[pxm0, pym0, pzm0], [pxm1, pym1, pzm1], [pxm2, pym2, pzm2]]]
    vector_data = [[vx0, vy0, vz0], ... [vxm, vym, vzm]]
    
    output data structure
    some_data_indexed = plane_data or vertex_data or vector_data
    plane_data = [[a0, b0, c0, d0], [a1, b1, c1, d1], ... [an, bn, cn, dn]]
    vertex_data = [[[px00, py00, pz00], [px01, py01, pz01], [px02, py02, pz02]],
                    ...,
                   [[pxn0, pyn0, pzn0], [pxn1, pyn1, pzn1], [pxn2, pyn2, pzn2]]]
    vector_data = [[vx0, vy0, vz0], ... [vxn, vyn, vzn]]
    """
    
    some_data_indexed = []
    
    for i in range(len(index_data)):
        some_data_indexed.append(some_data[index_data[i]])
        
    return some_data_indexed
    
def add_error_to_point_following_to_vector_dirct(point, error_length, vector):
    """
    input data structure
    point = [x, y, z]
    error_length = float (int)
    vector = [unit x vct, unit y vct, unit z vct]
    
    output data structure
    point_added_error_to_vector_direction = [xe, ye, ze]
    """
    
    point_with_error   = []
    unit_error         = []
    
    for i in range(len(point)):
        unit_error.append(error_length * vector[i])
    
    for i in range(len(point)):
        point_with_error.append(point[i] + unit_error[i])
    
    return point_with_error
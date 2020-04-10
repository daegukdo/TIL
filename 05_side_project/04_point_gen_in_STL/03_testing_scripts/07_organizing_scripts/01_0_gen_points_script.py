import math
import numpy as np
import csv
import random
from sklearn.neighbors import KDTree

### function

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
    
    vertex_group                       = []

    for i in range(len(point40_on_STL)):
        temp                           = []        
        for j, k in enumerate(vertex_data):
            if point40_on_STL[i] in k:
                temp.append(j)
                if len(temp) == 3:
                    break
        vertex_group.append(temp)

    vertex_selected_index              = []

    for i in range(len(vertex_group)):
        randomIndex                    = random.choice(vertex_group[i])
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
    
    rand_i, rand_j                     = np.random.rand(2)            # Two independent random numbers from a uniform distribution in the range (0, 1)
    theta                              = 2 * np.pi * rand_i           # Spherical coordinate theta
    phi                                = np.arccos(2 * rand_j - 1)    # Spherical coordinate phi, corrected for distribution bias
    x                                  = np.cos(theta) * np.sin(phi)  # Cartesian coordinate x
    y                                  = np.sin(theta) * np.sin(phi)  # Cartesian coordinate y
    z                                  = np.cos(phi)                  # Cartesian coordinate z
    vector                             = [x * length, y * length, z * length]
    # print(vector)

    return vector

def add_mm_error_to_point(point, max_error = 20):
    """
    input data structure
    point = [x, y, z] # x, y, z unit = mm
    
    output data structure
    point_added_error = [x', y', z']
    """
    
    point_added_error                  = point.copy()
    
    error                              = random.uniform(0, max_error)
    
    xyz_error                          = random_vector(error)

    point_added_error[0]              += xyz_error[0]
    point_added_error[1]              += xyz_error[1]
    point_added_error[2]              += xyz_error[2]
    
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
    
    plane_ABC_sqrt                     = math.sqrt(plane[0]*plane[0] + plane[1]*plane[1] + plane[2]*plane[2])
    dist                               = (plane[3] + plane[0] * point[0] + plane[1] * point[1] + plane[2] * point[2]) / plane_ABC_sqrt
    # print(dist)
    projected_point                    = point - dist * norm_vect
    
    on_the_plane_value                 = is_including_point(plane, projected_point)
    
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
    
    a                                  = plane[0]
    b                                  = plane[1]
    c                                  = plane[2]
    d                                  = plane[3]
    x                                  = point[0]
    y                                  = point[1]
    z                                  = point[2]
    
    included_value                     = a*x + b*y + c*z + d
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
    
    points40_with_error_on_plane       = []

    data_point_40_slt                  = point40_on_STL.copy()

    for i in range(len(data_point_40_slt)):        
        _point_added_error             = add_mm_error_to_point(data_point_40_slt[i])
        _point_on_plane                = find_projection_point_in_plane_3D(_point_added_error, 
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
    
    sum                                = 0
    for i in range(3):
        sum                            = sum + (point1[i] - point2[i])**2
    return math.sqrt(sum)

def get_closet_points(ref_points, trg_points):
    """
    input data structure
    ref_points = [[xr0, yr0, zr0], ... [xrn, yrn, zrn]]
    trg_points = [[xt0, yt0, zt0], ... [xtm, ytm, ztm]]
    
    output data structure (closet points in trg_points from ref_points)
    closet_points = [[xc0, yc0, zc0], ... [xcn, ycn, zcn]]
    """
    
    tree                                = KDTree(trg_points)
    nearest_dist, nearest_ind           = tree.query(ref_points, k=2)
    
    nearest_index                       = nearest_ind[:,1]
    closet_points                       = []
    
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
    
    some_data_indexed                     = []
    
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
    
    point_with_error                       = []
    unit_error                             = []
    
    for i in range(len(point)):
        unit_error.append(error_length * vector[i])
    
    for i in range(len(point)):
        point_with_error.append(point[i] + unit_error[i])
    
    return point_with_error

def get_normal_distribution_list(mu, sigma, num_of_list):
    """
    input data structure
    mu = float data
    sigma = float data
    num_of_list = int data
    
    output data structure
    normal_distribution_list = [n0, n1 ... nm] # m = num_of_list
    """
    
    norm_distr_list                        = []
    _mu, _sigma                            = mu, sigma
    norm_distr                             = []
    
    while(True):
        norm_distr                         = np.random.normal(_mu, _sigma, 10000)
        if(abs(mu - np.mean(norm_distr)) < 0.001):
            break
            
    for i in range(num_of_list):
        norm_distr_list.append(random.choice(norm_distr))
    
    return norm_distr_list

def is_data_stable(data_list, thr = 0.5):
    """
    input data structure
    data_list = [[xr0, yr0, zr0], ... [xrn, yrn, zrn]]
    thr = float data
    
    output data structure
    bool True (if all data have smaller diff. than mean + thr) || Flase
    """
    
    data_array                             = []
    if(type(data_list) == type([])):
        data_array                         = np.array(data_list)
    elif(type(data_list) == type(np.array([]))):
        data_array                         = data_list
    else:
        return "Wrong data type (data_list must be list type or nparray type)"
    
    sum_of_point_xyz                       = [0, 0, 0]
    
    for i in range(len(data_array)):
        for j in range(3):
            sum_of_point_xyz[j]           += data_array[i][j]
            
    mean_of_point_xyz                      = [0, 0, 0]
    
    for i in range(3):
        mean_of_point_xyz[i]               = sum_of_point_xyz[i] / float(len(data_array))
    
    for i in range(len(data_array)):
        value                              = get_dist_btw_2_3Dpoints(mean_of_point_xyz, data_array[i])
        # print(value)
        if(value < thr):
            pass
        else:
            return False
        
    return True

def eulerDegree2mtx(data):
    posX                                   = data[0]
    posY                                   = data[1]
    posZ                                   = data[2]
    pitch                                  = data[3] / 180 * 3.141592653589793238462643383279
    roll                                   = data[4] / 180 * 3.141592653589793238462643383279
    yaw                                    = data[5] / 180 * 3.141592653589793238462643383279
    
    Rx                                     = np.array([[1, 0, 0, 0],
                                                       [0, math.cos(pitch), -1 * math.sin(pitch), 0],
                                                       [0, math.sin(pitch), math.cos(pitch), 0],
                                                       [0, 0, 0, 1]])
    
    Ry                                     = np.array([[math.cos(roll), 0, math.sin(roll), 0],
                                                       [0, 1, 0, 0],
                                                       [-1 * math.sin(roll), 0, math.cos(roll), 0],
                                                       [0, 0, 0, 1]])
    
    Rz                                     = np.array([[math.cos(yaw), -1 * math.sin(yaw), 0, 0],
                                                       [math.sin(yaw), math.cos(yaw), 0, 0],
                                                       [0, 0, 1, 0],
                                                       [0, 0, 0, 1]])
    
    mtxR                                   = np.dot(Rz, np.dot(Ry, Rx))
    
    mtxR[0][3]                             = posX
    mtxR[1][3]                             = posY
    mtxR[2][3]                             = posZ
    
    return mtxR

def point2mtx(point):
    mtx                                    = np.array([[1, 0, 0, point[0]],
                                                      [0, 1, 0, point[1]],
                                                      [0, 0, 1, point[2]],
                                                      [0, 0, 0, 1       ]])
    
    return mtx

### main code

# num_of_iter                                = 10

num_of_files                               = 8

init_points_data_path                      = 'C:/Users/eornr/Desktop/source_crx/200331_point_gen/01_point_gen_in_STL/05_gen_point_init_planing_data/data'

STL_info_data_path                         = 'C:/Users/eornr/Desktop/source_crx/200331_point_gen/01_point_gen_in_STL/01_STL_data_to_npy/data'
info_data_prefix                           = ['/Fc1L', '/Tc1L', '/Fc1R', '/Tc1R',
                                            '/Fc2L', '/Tc2L', '/Fc2R', '/Tc2R']

point40_data_path                          = 'C:/Users/eornr/Desktop/source_crx/200331_point_gen/01_point_gen_in_STL/02_raw_40_point/data'

point_processed_data_path                  = 'C:/Users/eornr/Desktop/source_crx/200331_point_gen/01_point_gen_in_STL/07_gen_point_data_proto_v2/data'

# !!! // 0, 1, 2, 3, 4, 5, 6, 7
test_nof                                   = 1

# check file name
file_name                                  = point_processed_data_path + info_data_prefix[test_nof] + '_' + str(0) + '_points_processed'
print(file_name)

# load raw data
point_init_plan                            = np.load(init_points_data_path + info_data_prefix[test_nof] + '_plan.npy')
point40_on_STL                             = np.load(point40_data_path + info_data_prefix[test_nof] + 'points_40_selected.npy')
each_point_data                            = np.load(STL_info_data_path + info_data_prefix[test_nof] + '_femur_each_point_data.npy')
vertex_data                                = np.load(STL_info_data_path + info_data_prefix[test_nof] + '_femur_vertex_data.npy')
plane_data                                 = np.load(STL_info_data_path + info_data_prefix[test_nof] + '_femur_plane_data.npy')
vector_data                                = np.load(STL_info_data_path + info_data_prefix[test_nof] + '_femur_vector_data.npy')

# load sim data
sim_file_path                              = "C:/Users/eornr/Desktop/source_crx/200331_point_gen/01_point_gen_in_STL/06_gen_point_data_proto/sim_pose/"
sim_file_names                             = ["left_femur_sim", "left_tibia_sim"]

left_femur_position_pose_data_list         = np.load(sim_file_path + sim_file_names[0] + '.npy')
left_tibia_position_pose_data_list         = np.load(sim_file_path + sim_file_names[1] + '.npy')

## gen positioning mtx
# FL, TL, FR, TR
trns_mtx_list                              = [left_femur_position_pose_data_list,
                                              left_tibia_position_pose_data_list,
                                              [625, -195, 225, 220, 0, 0],
                                              [625, -195, 225, 200, 0, 180]]

transform_data_euler_degree_rot            = []

if("F" in file_name and "L" in file_name):
    transform_data_euler_degree_rot        = trns_mtx_list[0]
elif("T" in file_name and "L" in file_name):
    transform_data_euler_degree_rot        = trns_mtx_list[1]
elif("F" in file_name and "R" in file_name):
    transform_data_euler_degree_rot        = trns_mtx_list[2]
elif("T" in file_name and "R" in file_name):
    transform_data_euler_degree_rot        = trns_mtx_list[3]

transform_data_mtx                         = []

for i in range(len(transform_data_euler_degree_rot)):
    transform_data_mtx.append(eulerDegree2mtx(transform_data_euler_degree_rot[i]))

for iter_mtx in range(len(transform_data_mtx)):
    ## gen point init PLAN probing

    # select planer init point (on bone model)
    point_init_plan_on_bone                = get_closet_points(point_init_plan, each_point_data)

    # gen point
    select_vertex_index_raw_init, _        = select_random_vertex_index(point_init_plan_on_bone, vertex_data)

    point_init_with_error_on_plane         = cal_points40_with_error_on_plane(point_init_plan_on_bone, 
                                                                      get_data_with_index(select_vertex_index_raw_init, plane_data), 
                                                                      get_data_with_index(select_vertex_index_raw_init, vector_data)) 

    nearest_point_init_with_error_on_plane = get_closet_points(point_init_with_error_on_plane, each_point_data)

    select_vertex_index_nearest_init, _    = select_random_vertex_index(nearest_point_init_with_error_on_plane, vertex_data)

    nearest_point_init_vector              = get_data_with_index(select_vertex_index_nearest_init, vector_data)

    point_init_with_uncertainty_error      = []
    error_value_list                       = get_normal_distribution_list(0, 0.3, len(nearest_point_init_with_error_on_plane))

    for i in range(len(nearest_point_init_with_error_on_plane)):
        error_value                        = error_value_list[i]
        tmp_point                          = add_error_to_point_following_to_vector_dirct(nearest_point_init_with_error_on_plane[i],
                                                                                          error_value,
                                                                                          nearest_point_init_vector[i])

        point_init_with_uncertainty_error.append(tmp_point)

    ## gen point ICP probing

    # gen point
    select_vertex_index_raw, _             = select_random_vertex_index(point40_on_STL, vertex_data)

    points40_with_error_on_plane           = cal_points40_with_error_on_plane(point40_on_STL, 
                                                                              get_data_with_index(select_vertex_index_raw, plane_data), 
                                                                              get_data_with_index(select_vertex_index_raw, vector_data)) 

    nearest_points40_with_error_on_plane   = get_closet_points(points40_with_error_on_plane, each_point_data)

    select_vertex_index_nearest, _         = select_random_vertex_index(nearest_points40_with_error_on_plane, vertex_data)

    nearest_points40_vector                = get_data_with_index(select_vertex_index_nearest, vector_data)

    points40_with_uncertainty_error        = []
    error_value_list                       = get_normal_distribution_list(0, 0.3, len(nearest_points40_with_error_on_plane))

    for i in range(len(nearest_points40_with_error_on_plane)):
        error_value                        = error_value_list[i]
        tmp_point                          = add_error_to_point_following_to_vector_dirct(nearest_points40_with_error_on_plane[i],
                                                                                       error_value,
                                                                                       nearest_points40_vector[i])

        points40_with_uncertainty_error.append(tmp_point)

    points400_with_uncertainty_error       = []

    for i in range(len(points40_with_uncertainty_error)):
        while(True):
            tmp                            = []
            error_value_list               = get_normal_distribution_list(0, 0.3, 10)
            point                          = points40_with_uncertainty_error[i]
            for j in range(10):
                tmp.append(add_mm_error_to_point(point, abs(error_value_list[j])))
            
            if is_data_stable(tmp):
                for k in range(len(tmp)):
                    points400_with_uncertainty_error.append(tmp[k])
                break

    regi_data_points                       = point_init_with_uncertainty_error + points400_with_uncertainty_error



    regi_points_trans                      = []

    for i in range(len(regi_data_points)):
        tmp_mtx                            = np.dot(transform_data_mtx[iter_mtx], point2mtx(regi_data_points[i]))
        regi_points_trans.append([tmp_mtx[0][3], 
                                  tmp_mtx[1][3], 
                                  tmp_mtx[2][3]])

    export_filename = file_name + '_all_t' + f'{iter_mtx:03}' + '.txt'

    with open(export_filename, 'w') as file:
        for i in range(len(regi_points_trans)):
            tmp_point                      = regi_points_trans[i]
            tmp_data_str                   = ""
            for j in range(len(tmp_point)):
                tmp_data_str              += str(tmp_point[j])
                if j < 2:
                    tmp_data_str          += ', '
                else:
                    tmp_data_str          += '\n'
            file.write(tmp_data_str)

    print(export_filename)
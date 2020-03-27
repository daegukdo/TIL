import struct
import numpy as np

def get_equation_plane_from_3points(points3list):  
    x1 = points3list[0][0]
    y1 = points3list[0][1]
    z1 = points3list[0][2]
    x2 = points3list[1][0]
    y2 = points3list[1][1]
    z2 = points3list[1][2]
    x3 = points3list[2][0]
    y3 = points3list[2][1]
    z3 = points3list[2][2]
    
    a1 = x2 - x1 
    b1 = y2 - y1 
    c1 = z2 - z1 
    a2 = x3 - x1 
    b2 = y3 - y1 
    c2 = z3 - z1 
    
    a = b1 * c2 - b2 * c1 
    b = a2 * c1 - a1 * c2 
    c = a1 * b2 - b1 * a2 
    d = (- a * x1 - b * y1 - c * z1) 
    
    return [a, b, c, d]


# set STL file path
# C:/Users/eornr/Desktop/source_crx/200325_registration_valid_test_cadaver_data
dir_path = "C:/Users/eornr/Desktop/source_crx/200325_registration_valid_test_cadaver_data/"
file_name = "Femur_bone_c1R.stl"
file_path = dir_path + file_name

# store each point 
each_point_data = []

# store plane with each info.
vertex_data = []
plane_data = []
vector_data = []
### menu_dict = dict(zip(drink_list, price_list))

# read STL file using open() with 'rb' keyword (rb : read binary)
with open(file_path, "rb") as parse :
    
    # first 80 bytes : header
    head = parse.read(80)
    
    # 4 bytes : number of facets in file
    num_of_triangles_raw = parse.read(4)
    # 4 bytes to unsigned long int
    num_of_triangles=struct.unpack("<L", num_of_triangles_raw)
    print("number of facets : " + str(num_of_triangles[0]))
    print("   ")
    
    for i in range(int(num_of_triangles[0])):
        # print("facet number : " + str(i))
        
        ### normal vector
        # 1) 4 * 3 = normal (i, j, k)
        _data_tmp = []
        for ii in range(3):
            linedata = parse.read(4)
            # 4 bytes to float
            linedata = struct.unpack("<f", linedata)
            _data_tmp.append(float(linedata[0]))
        vector_data.append(_data_tmp)
            
        ### vertex points
        _data_vtx_tmp = []
        # 2) 4 * 3 = vertex 1 (x, y, z)
        _data_tmp = []
        for ii in range(3):
            linedata = parse.read(4)
            # 4 bytes to float
            linedata = struct.unpack("<f", linedata)
            _data_tmp.append(float(linedata[0]))
        _data_vtx_tmp.append(_data_tmp) 
        if _data_tmp in each_point_data:
            pass
        else:
            each_point_data.append(_data_tmp)
        
        # 3) 4 * 3 = vertex 2 (x, y, z)
        _data_tmp = []
        for ii in range(3):
            linedata = parse.read(4)
            # 4 bytes to float
            linedata = struct.unpack("<f", linedata)
            _data_tmp.append(float(linedata[0]))
        _data_vtx_tmp.append(_data_tmp) 
        if _data_tmp in each_point_data:
            pass
        else:
            each_point_data.append(_data_tmp)
            
        # 4) 4 * 3 = vertex 3 (x, y, z)
        _data_tmp = []
        for ii in range(3):
            linedata = parse.read(4)
            # 4 bytes to float
            linedata = struct.unpack("<f", linedata)
            _data_tmp.append(float(linedata[0]))
        _data_vtx_tmp.append(_data_tmp) 
        if _data_tmp in each_point_data:
            pass
        else:
            each_point_data.append(_data_tmp)
        
        vertex_data.append(_data_vtx_tmp)
        plane_data.append(get_equation_plane_from_3points(_data_vtx_tmp))
            
        # attribute
        for iii in range(1):
            linedata=parse.read(2)
            # 2 bytes to unsigned int
            linedata=struct.unpack("<H", linedata)
        # print("   ")

print(len(each_point_data))

print(len(vertex_data))
print(len(plane_data))
print(len(vector_data))

# make_prefix
prefix = ''

if 'Femur' in file_path:
    prefix += 'F'
elif 'Tibia' in file_path:
    prefix += 'T'
    
prefix += file_path[-7:-4]

export_dir_path = 'data/'


np.save(export_dir_path + prefix +'_femur_each_point_data', np.array(each_point_data))
np.save(export_dir_path + prefix +'_femur_vertex_data', np.array(vertex_data))
np.save(export_dir_path + prefix +'_femur_plane_data', np.array(plane_data))
np.save(export_dir_path + prefix +'_femur_vector_data', np.array(vector_data))
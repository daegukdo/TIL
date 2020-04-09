import numpy as np
import math
from xml.etree.ElementTree import parse
import glob
import pprint

def mtx_value_list_2_mtx_array(mtx_value_list):
    mtx_array = []
    
    count = 0
    for i in range(4):
        tmp = []
        for j in range(4):
            tmp.append(float(mtx_value_list[j + count]))
        count = count + 4
        mtx_array.append(tmp)
        
    return mtx_array

def mtx2euler(mtx) :
    dLocSqrt = (mtx[0][0] * mtx[0][0] +  mtx[1][0] * mtx[1][0])
    
    if(dLocSqrt<0.0):
        dLocSqrt = 0.0
    else:
        dLocSqrt= math.sqrt(dLocSqrt)
    
    dLocRy = math.atan2(-mtx[2][0], dLocSqrt)
    dLocCy = math.cos(dLocRy)
 
    if (dLocCy < 0.001745328365898):
        Rx = 0.0
        Ry = dLocRy
        Rz = math.atan2(-mtx[0][1], mtx[1][1])
    else:
        Rx = math.atan2(mtx[2][1]/dLocCy, mtx[2][2]/dLocCy)
        Ry = dLocRy
        Rz = math.atan2(mtx[1][0]/dLocCy, mtx[0][0]/dLocCy)
        
    X = mtx[0][3]
    Y = mtx[1][3]
    Z = mtx[2][3]
    Rx = Rx * 180 / 3.141592653589793238462643383279
    Ry = Ry * 180 / 3.141592653589793238462643383279
    Rz = Rz * 180 / 3.141592653589793238462643383279
 
    return np.array([X, Y, Z, Rx, Ry, Rz])

def eulerDegree2mtx(data):
    posX = data[0]
    posY = data[1]
    posZ = data[2]
    pitch = data[3] / 180 * 3.141592653589793238462643383279
    roll = data[4] / 180 * 3.141592653589793238462643383279
    yaw = data[5] / 180 * 3.141592653589793238462643383279
    
    Rx = np.array([[1, 0, 0, 0],
                   [0, math.cos(pitch), -1 * math.sin(pitch), 0],
                   [0, math.sin(pitch), math.cos(pitch), 0],
                   [0, 0, 0, 1]])
    
    Ry = np.array([[math.cos(roll), 0, math.sin(roll), 0],
                   [0, 1, 0, 0],
                   [-1 * math.sin(roll), 0, math.cos(roll), 0],
                   [0, 0, 0, 1]])
    
    Rz = np.array([[math.cos(yaw), -1 * math.sin(yaw), 0, 0],
                   [math.sin(yaw), math.cos(yaw), 0, 0],
                   [0, 0, 1, 0],
                   [0, 0, 0, 1]])
    
    mtxR = np.dot(Rz, np.dot(Ry, Rx))
    
    mtxR[0][3] = posX
    mtxR[1][3] = posY
    mtxR[2][3] = posZ
    
    return mtxR

init_plan_data_path = 'C:/Users/eornr/Desktop/source_crx/200331_point_gen/01_point_gen_in_STL/05_gen_point_init_planing_data/raw_data/'

file_ext = '.xml'
xml_data_name = ['c1L_plan', 
                 'c1R_plan', 
                 'c2L_plan', 
                 'c2R_plan']

femur_imp_model_mtx = []
tibia_imp_model_mtx = []

for fi in range(len(xml_data_name)):
    tree = parse(init_plan_data_path + xml_data_name[fi] + file_ext)
    main_root = tree.getroot()

    femur_imp_model = main_root.getchildren()[2].getchildren()[1].getchildren()[0]
    tibia_imp_model = main_root.getchildren()[3].getchildren()[1].getchildren()[0]
    
    value_split_f = femur_imp_model.find("MatrixModel2Local").text.split(',')
    value_split_t = tibia_imp_model.find("MatrixModel2Local").text.split(',')
    
    femur_imp_model_mtx.append(value_split_f)
    tibia_imp_model_mtx.append(value_split_t)

imp_mtxs = []

for i in range(4):
    imp_mtxs.append(np.array(mtx_value_list_2_mtx_array(femur_imp_model_mtx[i])))
    imp_mtxs.append(np.array(mtx_value_list_2_mtx_array(tibia_imp_model_mtx[i])))

result_data_path = 'C:/Users/eornr/Desktop/source_crx/200331_point_gen/01_point_gen_in_STL/06_gen_point_data_proto/03_registration_tester/result/'
mtx_str = 'mtx'
log_str = 'log'

result_files = glob.glob(result_data_path + '*')

# for export file name
export_file_name_list = []
count = 0

# Fc1L, Fc1R, Fc2L, Fc2R, Tc1L, Tc1R, Tc2L, Tc2R, 
plan_indexer_list = []

for file_name in result_files:
    if("mtx" in file_name):
        if("Fc1L" in file_name):
            plan_indexer_list.append(0)
            export_file_name_list.append("Fc1L" + "_" + str(count))
        elif("Fc1R" in file_name):
            plan_indexer_list.append(1)
            export_file_name_list.append("Fc1R" + "_" + str(count))
        elif("Fc2L" in file_name):
            plan_indexer_list.append(2)
            export_file_name_list.append("Fc2L" + "_" + str(count))
        elif("Fc2R" in file_name):
            plan_indexer_list.append(3)
            export_file_name_list.append("Fc2R" + "_" + str(count))
        elif("Tc1L" in file_name):
            plan_indexer_list.append(4)
            export_file_name_list.append("Tc1L" + "_" + str(count))
        elif("Tc1R" in file_name):
            plan_indexer_list.append(5)
            export_file_name_list.append("Tc1R" + "_" + str(count))
        elif("Tc2L" in file_name):
            plan_indexer_list.append(6)
            export_file_name_list.append("Tc2L" + "_" + str(count))
        elif("Tc2R" in file_name):
            plan_indexer_list.append(7)
            export_file_name_list.append("Tc2R" + "_" + str(count))
            
    count = count + 1

# FL, TL, FR, TR
trns_mtx_list                   = [[625, 195, 225, 220, 0, 180],
                                   [625, 195, 225, 200, 0, 0],
                                   [625, -195, 225, 220, 0, 0],
                                   [625, -195, 225, 200, 0, 180]]

transform_data_euler_degree_rot = []
ans_mtx                         = []

for file_name in result_files:
    if("mtx" in file_name):
        if("F" in file_name and "L" in file_name and "trs" in file_name):
            transform_data_euler_degree_rot = trns_mtx_list[0]
        elif("T" in file_name and "L" in file_name and "trs" in file_name):
            transform_data_euler_degree_rot = trns_mtx_list[1]
        elif("F" in file_name and "R" in file_name and "trs" in file_name):
            transform_data_euler_degree_rot = trns_mtx_list[2]
        elif("T" in file_name and "R" in file_name and "trs" in file_name):
            transform_data_euler_degree_rot = trns_mtx_list[3]
        else:
            transform_data_euler_degree_rot = [0, 0, 0, 0, 0, 0]

        ans_mtx.append(eulerDegree2mtx(transform_data_euler_degree_rot))

log_list = []
mtx_of_exp_list = []

for i in range(len(result_files)):
    file_path_str = result_files[i]
    if(log_str in file_path_str):
        with open(file_path_str) as file:
            log = ""
            for line in file:
                log = log + line
            log_list.append(log)
    elif(mtx_str in file_path_str):
        with open(file_path_str) as file:
            mtx_of_exp = []
            for line in file:
                _line = line.split('\n')
                each_value = _line[0].split(',')
                tmp = []
                for i in range(len(each_value)):
                    tmp.append(float(each_value[i]))
                mtx_of_exp.append(tmp)
            mtx_of_exp_list.append(np.array(mtx_of_exp))

registration_error_in_imp_space_list = []

for i in range(len(mtx_of_exp_list)):
    # Te = (pose * plan)^-1 * regi. * plan
    Te = np.dot(np.dot(np.linalg.inv(np.dot(ans_mtx[i], imp_mtxs[plan_indexer_list[i]])), 
                       np.linalg.inv(mtx_of_exp_list[i])), 
                imp_mtxs[plan_indexer_list[i]])
    registration_error_in_imp_space_list.append(mtx2euler(Te))

eval_file_names = []

for i in range(len(result_files)):
    if (i % 2 == 0):
        eval_file_names.append(result_files[i])

for i in range(len(mtx_of_exp_list)):
    with open("result/" + "result_" + export_file_name_list[i] + eval_file_names[i][-8:-4] + ".txt", 'w') as file:
        file.writelines(log_list[i])
        file.writelines("  ")
        file.writelines("\n")
        file.writelines(" ------- ")
        file.writelines("\n")
        file.writelines("  ")
        file.writelines("\n")
        for j in range(len(registration_error_in_imp_space_list[i])):
            file.writelines(str(registration_error_in_imp_space_list[i][j]))
            file.writelines("\n")
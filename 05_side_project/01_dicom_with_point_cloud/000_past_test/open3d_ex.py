import numpy as np
from open3d import *

if __name__ == "__main__":

    print("Load a ply point cloud, print it, and render it")
    pcd = read_point_cloud("coronal_line_from_CT.ply")
    print(pcd)
    print(np.asarray(pcd.points))
    draw_geometries([pcd])
    
    print("Paint Surface")
    pcd.paint_uniform_color([1, 0.706, 0])
    draw_geometries([pcd])
    print("")

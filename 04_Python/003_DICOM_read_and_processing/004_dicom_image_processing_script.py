import numpy as np
import pydicom
import glob
import os

dcmlists = glob.glob(os.path.join("DICOM/S95280/S2020/", "*"))

for i in range(len(dcmlists)):
    file_path = dcmlists[i]
    file_name = os.path.basename(file_path)

    try:
        dc = pydicom.dcmread(file_path)

        image = dc.pixel_array
        image = image.astype(np.int16)
        image[(image > 380) & (image < 1500)] += 1024

        dc.pixel_array.flat = np.array(image, dtype=np.int16).flat
        dc.PixelData = dc.pixel_array.tobytes()
        
        result_file_name = os.path.join("DICOM_cvt/", os.path.splitext(file_name)[0] + str(i) + ".dcm")
        
        dc.save_as(result_file_name)

        print(result_file_name)
    except AttributeError:
        print("AttributeError : wrong attribute")
    except:
        print("Error")
    
print("fin.")

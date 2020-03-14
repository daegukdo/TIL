#include "registrationP2M.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include<algorithm>

using namespace std;

double* loadPointDataFromCSmatTxt(string filePath);

int main()
{
	double* MSEArrs = new double();

	string filePath1 = "data\\_CollectedPointsFemur1.txt";
	double* m_pData_1 = new double();
    m_pData_1 = loadPointDataFromCSmatTxt(filePath1);

	registrationP2M::CPointSet points1 = registrationP2M::CPointSet(3, m_pData_1);

	string filePath2 = "data\\_CollectedPointsFemur2.txt";
	double* m_pData_2 = new double();
    m_pData_2 = loadPointDataFromCSmatTxt(filePath2);

	registrationP2M::CPointSet points2 = registrationP2M::CPointSet(3, m_pData_2);

	double getMSEreulst = points1.GetMSE(points2, MSEArrs);

	for(int i = 0; i < 3; i++)
	{
		cout << MSEArrs[i] << endl;
	}

	cout << getMSEreulst << endl;

	char* stlFilePath = "data\\Femur_.stl";
	registrationP2M::CReferenceModel boneSTL = registrationP2M::CReferenceModel();
	if(boneSTL.LoadData(stlFilePath))
	{
		cout << "load" << endl;
	}
	
	//char* objFilePath = "data\\Femur.obj";
	//registrationP2M::CReferenceModel boneOBJ = registrationP2M::CReferenceModel();
	//if(boneOBJ.LoadDataOBJ(objFilePath))
	//{
	//	cout << "load" << endl;
	//}

	// fin.
	return 0;
}

double* loadPointDataFromCSmatTxt(string filePath)
{
	// num of point * x,y,z .. double array

	// read raw point data .txt
	vector<double> pointData;

	ifstream openFile(filePath);

	if( openFile.is_open() )
	{
		string line;

		while(getline(openFile, line))
		{
			stringstream ss(line);
			int count = 0;

			while(ss.good())
			{
				string substr;
                getline( ss, substr, ',' );

				if(count == 14 || count == 13 || count ==12)
				{
					pointData.push_back(stod(substr));
				}

				count++;
			}
		}

		openFile.close();
	}

	// set.
	int numOfDatas = pointData.capacity();
	double* m_pData_ = new double[numOfDatas];

	for(int i = 0; i < numOfDatas; i++)
	{
		m_pData_[i] = pointData[i];
	}
	
	return m_pData_;

	// copy(m_pData_, m_pData_ + numOfPoints, targetArray);
	// memcpy(targetArray, m_pData_, sizeof(m_pData_));

	// delete[] m_pData_;
}
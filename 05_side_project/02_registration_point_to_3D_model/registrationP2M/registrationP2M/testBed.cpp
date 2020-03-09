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
	string filePath = "data\\_CollectedPointsFemur.txt";
	double* m_pData_ = new double();
    m_pData_ = loadPointDataFromCSmatTxt(filePath);

	registrationP2M::CPointSet points = registrationP2M::CPointSet(3, m_pData_);

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
	int numOfPoints = pointData.capacity();
	double* m_pData_ = new double[numOfPoints];

	for(int i = 0; i < numOfPoints; i++)
	{
		m_pData_[i] = pointData[i];
	}
	
	return m_pData_;

	// copy(m_pData_, m_pData_ + numOfPoints, targetArray);
	// memcpy(targetArray, m_pData_, sizeof(m_pData_));

	// delete[] m_pData_;
}
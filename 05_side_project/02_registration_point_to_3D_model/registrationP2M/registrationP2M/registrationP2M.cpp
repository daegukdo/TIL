// for test
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// for registration
#include "registrationP2M.h"
// #pragma comment(lib, "ANN.lib")

#include <array>

namespace registrationP2M
{
	//////////////////////////////////////////////////////////////////////////////
	// CPointSet
	//////////////////////////////////////////////////////////////////////////////
	CPointSet::CPointSet()
	{
		m_iNumPoints = 0;
		m_pData = NULL;
	}

	CPointSet::CPointSet(int iNumPoints)
	{
		m_iNumPoints = iNumPoints;
		m_pData = new double[m_iNumPoints*DIM];
		memset(m_pData, 0, m_iNumPoints*DIM*sizeof(double));
	}

	CPointSet::CPointSet(const CPointSet& other)
	{
		m_iNumPoints = other.m_iNumPoints;
		m_pData = new double[m_iNumPoints*DIM];
		memcpy(m_pData, other.m_pData, m_iNumPoints*DIM*sizeof(double));
	}

	CPointSet::CPointSet(int iNumPoints, double* pPoints)
	{
		m_iNumPoints = iNumPoints;
		m_pData = new double[m_iNumPoints*DIM];
		memcpy(m_pData, pPoints, m_iNumPoints*DIM*sizeof(double));
	}

	CPointSet::~CPointSet()
	{
		if(m_pData != NULL)
			delete [] m_pData;
	}

	bool CPointSet::SetPointSet(double* pPoints)
	{
		if (m_pData != NULL)
		{
			memcpy(m_pData, pPoints, m_iNumPoints*DIM*sizeof(double));
			return true;
		}
		else
		{
			return false;
		}
	}

	CPointSet CPointSet::GetPointSet(int iIndex) const
	{
		if(iIndex < m_iNumPoints)
		{
			double* pPoints = new double[DIM];
			memcpy(pPoints, m_pData+DIM*iIndex, DIM*sizeof(double));
			CPointSet ret(1, pPoints);
			delete [] pPoints;

			return ret;
		}
		else
			return CPointSet();
	}

	CPointSet CPointSet::GetPointSet(vector<int> vIndex) const
	{
		int i;
		int iNumPoints = vIndex.size();
		double* pPoints = new double[iNumPoints*DIM];
		for(i = 0; i < iNumPoints; i++)
		{
			if(vIndex[i] < m_iNumPoints)
				memcpy(pPoints+DIM*i, m_pData+DIM*vIndex[i], DIM*sizeof(double));
			else
			{
				iNumPoints = 0;
				delete [] pPoints;
				pPoints = NULL;
				break;
			}
		}

		CPointSet ret(iNumPoints, pPoints);
		if(pPoints != NULL) delete [] pPoints;

		return ret;
	}
}

int main()
{
	// read raw point data .txt
	vector<double> pointData;

	string filePath = "data\\_CollectedPointsFemur.txt";

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

	// cal.
	double* m_pData_ = new double[pointData.capacity()];

	for(int i = 0; i < pointData.capacity(); i++)
	{
		m_pData_[i] = pointData[i];
	}

	delete[] m_pData_;


	// fin.
	return 0;
}
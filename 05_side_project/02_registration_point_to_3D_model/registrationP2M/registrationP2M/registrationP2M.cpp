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

	void CPointSet::GetDistArr(double* pPoint, double* pDistArr) const
	{
		int i, j;
		memset(pDistArr, 0, m_iNumPoints*sizeof(double));

		for(i = 0; i < m_iNumPoints; i++)
			for(j = 0; j < DIM; j++)
				pDistArr[i] += (m_pData[DIM*i+j] - pPoint[j]) * (m_pData[DIM*i+j] - pPoint[j]);
	}

	double CPointSet::GetMSE(const CPointSet& other, double* pSquareErrorArr) const
	{
		if(other.GetNumPoints() == m_iNumPoints && m_iNumPoints > 0)
		{
			memset(pSquareErrorArr, 0, m_iNumPoints*sizeof(double));
			double mse = 0.0;

			for(int i = 0; i < m_iNumPoints; i++)
			{
				for(int j = 0; j < DIM; j++)
				{	
					pSquareErrorArr[i] += (m_pData[DIM*i+j]-other.m_pData[DIM*i+j])*(m_pData[DIM*i+j]-other.m_pData[DIM*i+j]);		
				}
				mse += pSquareErrorArr[i];
			}

			return mse/(double)m_iNumPoints;
		}
		else
			return 0.0;
	}

	double* CPointSet::GetPointSetRaw(int iIndex) const
	{
		return m_pData + DIM * iIndex;
	}

	CPointSet& CPointSet::operator=(const CPointSet& other)
	{
		if(m_pData != NULL)
			delete [] m_pData;
		m_iNumPoints = other.m_iNumPoints;
		m_pData = new double[m_iNumPoints*DIM];
		memcpy(m_pData, other.m_pData, DIM * m_iNumPoints * sizeof(double));

		return *this;
	}
}
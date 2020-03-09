#pragma once
#include <memory>
#include <cmath>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
// #include <ANN.h>
// #include <Eigen/Eigen>
#include <deque>

using namespace std;

namespace registrationP2M
{
	//////////////////////////////////////////////////////////////////////////////
	//	constants
	static const double ZERO_PRECISION = 1e-4;

	class CPointSet
	{
	protected:
		int m_iNumPoints;
		double* m_pData;		// size: m_iNumPoints * DIM_POINT

	public:
		static const int DIM = 3;

		CPointSet();
		CPointSet(int iNumPoints);
		CPointSet(const CPointSet& other);
		CPointSet(int iNumPoints, double* pPoints);
		~CPointSet();

		bool SetPointSet(double* pPoints);
		CPointSet GetPointSet(int iIndex) const;
		CPointSet GetPointSet(vector<int> vIndex) const;
	};
}
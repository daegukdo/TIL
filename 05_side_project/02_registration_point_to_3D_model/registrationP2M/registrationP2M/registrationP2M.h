#pragma once
#include <memory>
#include <cmath>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <ANN.h>
#include <Eigen/Eigen>
#include <deque>
#include <fstream>

using namespace std;

namespace registrationP2M
{
	//////////////////////////////////////////////////////////////////////////////
	//	constants
	static const double ZERO_PRECISION = 1e-4;

	//////////////////////////////////////////////////////////////////////////////
	// CPointSet
	class CPointSet
	{
	protected:
		int m_iNumPoints;
		double* m_pData;		// size: m_iNumPoints * DIM_POINT

	public:
		static const int DIM = 3; // X,Y,Z

		CPointSet();
		CPointSet(int iNumPoints);
		CPointSet(const CPointSet& other);
		CPointSet(int iNumPoints, double* pPoints);
		~CPointSet();

		bool SetPointSet(double* pPoints);
		CPointSet GetPointSet(int iIndex) const;
		CPointSet GetPointSet(vector<int> vIndex) const;
		void GetDistArr(double* pPoint, double* pDistArr) const;
		double GetMSE(const CPointSet& other, double* pSquareErrorArr) const;

		int GetNumPoints() const { return m_iNumPoints; }
		double* GetPointSetRaw(int iIndex) const;
		
		CPointSet& operator=(const CPointSet& other);
	};

	//////////////////////////////////////////////////////////////////////////////
	// CMesh
	class CMesh : public CPointSet
	{
	private:
		bool GetPointInTriangularMesh(double* inPoint, double* outPoint);
		bool GetPointInLine(double* pPt1, double* pPt2, double* inPt, double* outPt);

	public:
		static const int DIM_MESH = 3;
		CMesh(double *pPoints);

		void GetClosestPoint(double* inPoint, double* outPoint);
	};

	//////////////////////////////////////////////////////////////////////////////
	// CMapPointToMesh
	class CMapPointToMesh
	{
	private:
		int m_iNumPoints;
		int m_iNumMeshes;
		deque<CMesh>* m_pMap;

	public:
		CMapPointToMesh(int iNumMeshes, int* pMeshInform, const CPointSet& basePointSet);
		~CMapPointToMesh();
		bool GetCorrMeshList(int iPointIndex, deque<CMesh> **listMeshes);
	};

	//////////////////////////////////////////////////////////////////////////////
	// CPointCloudbyANN
	class CPointCloudbyANN
	{
	private:
		int m_nDIM;
		int m_nDataPts;
		ANNpointArray m_arDataPts;
		ANNkd_tree* m_pkdTree;

	public:
		CPointCloudbyANN();
		~CPointCloudbyANN();

		int GetNumDataPoints() const { return m_nDataPts; };
		bool SetDataPoints(CPointSet& points);
		int GetNearestPointIndex(double* queryPt, const int& dim, double &dist) const; // dist: squared distance
	};

	//////////////////////////////////////////////////////////////////////////////
	// CReferenceModel
	class CReferenceModel
	{
	private:
		CPointSet* m_pRefPts;
		CMapPointToMesh* m_pMapPointToMesh;
		CPointCloudbyANN m_kdTree;

		int m_iNumPoints;
		int m_iNumMeshes;

	public:
		CReferenceModel();
		~CReferenceModel();

		bool LoadData(char* pFileName);
		bool LoadDataOBJ(char* pFileName);
		bool LoadData(int iNumPoints, double* pRefPts, int iNumMeshes, int* pMeshInform);
		bool GetNearestPoint(double* inPoint, double& dist, double* outPoint);
	};
}
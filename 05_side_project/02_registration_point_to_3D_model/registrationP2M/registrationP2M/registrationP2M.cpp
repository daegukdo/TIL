#include "registrationP2M.h"
#pragma comment(lib, "ANN.lib")

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

	//////////////////////////////////////////////////////////////////////////////
	// CMesh
	//////////////////////////////////////////////////////////////////////////////
	CMesh::CMesh(double* pPoints)
		: CPointSet(DIM_MESH, pPoints)
	{
	}

	void CMesh::GetClosestPoint(double* inPoint, double* outPoint)
	{
		int i, j;
		double tPoint[CPointSet::DIM];

		if(GetPointInTriangularMesh(inPoint, tPoint) == true)
		{
			memcpy(outPoint, tPoint, CPointSet::DIM*sizeof(double));
		}
		else
		{
			double pTempCandPts[CPointSet::DIM*CMesh::DIM_MESH];
			double pLinePt1[CPointSet::DIM];
			double pLinePt2[CPointSet::DIM];
			double* pPtr;

			for(i = 0; i < CMesh::DIM_MESH; i++)
			{
				memcpy(pLinePt1, m_pData+CPointSet::DIM*i, CPointSet::DIM*sizeof(double));
				memcpy(pLinePt2, m_pData+CPointSet::DIM*((i+1)%CMesh::DIM_MESH), CPointSet::DIM*sizeof(double));

				if(GetPointInLine(pLinePt1, pLinePt2, inPoint, tPoint) == true)
					memcpy(pTempCandPts+CPointSet::DIM*i, tPoint, CPointSet::DIM*sizeof(double));
				else
				{
					double tDist1 = 0.0;
					double tDist2 = 0.0;

					for(j = 0; j < CPointSet::DIM; j++)
					{
						tDist1 += (pLinePt1[j] - inPoint[j]) * (pLinePt1[j] - inPoint[j]); // square dist.
						tDist2 += (pLinePt2[j] - inPoint[j]) * (pLinePt2[j] - inPoint[j]);
					}

					pPtr = (tDist1 < tDist2) ? pLinePt1 : pLinePt2;
					memcpy(pTempCandPts+CPointSet::DIM*i, pPtr, CPointSet::DIM*sizeof(double));
				}
			}

			double pTempArrDist[CMesh::DIM_MESH];
			CPointSet tCandPtSet(CMesh::DIM_MESH, pTempCandPts);

			tCandPtSet.GetDistArr(inPoint, pTempArrDist);

			pPtr = min_element(pTempArrDist, pTempArrDist+CMesh::DIM_MESH);
			memcpy(outPoint, tCandPtSet.GetPointSetRaw(pPtr-pTempArrDist), CPointSet::DIM*sizeof(double));
		}

	}

	bool CMesh::GetPointInTriangularMesh(double* inPoint, double* outPoint)
	{
		int i;
		const int iDIM = CPointSet::DIM;

		// triangluar mesh: vPoints4plane[0], vPoints4plane[1], and vPoints4plane[2]
		double p1[iDIM];
		double p2[iDIM];
		
		for(i = 0; i < iDIM; i++)
		{
			p1[i] = m_pData[iDIM+i] - m_pData[i];
			p2[i] = m_pData[2*iDIM+i] - m_pData[i];
		}
						
		double a_dot_b = 0.0;
		for(i = 0; i < iDIM; ++i)
			a_dot_b += p1[i] * p2[i];
		
		if(fabs(a_dot_b-1.0) > ZERO_PRECISION) // if a and b are not colinear, 
		{
			double n[iDIM];
			n[0] = p1[1] * p2[2] - p1[2] * p2[1];
			n[1] = p1[2] * p2[0] - p1[0] * p2[2];
			n[2] = p1[0] * p2[1] - p1[1] * p2[0];
			
			double norm = 0.0;
			for(i = 0; i < iDIM; ++i)
				norm += n[i]*n[i];
			norm = sqrt(norm);

			if(norm < ZERO_PRECISION) return false;

			for(i = 0; i < iDIM; ++i)
				n[i] /= norm;

			// outPoint: point in the plane
			double inPoint_dot_n = 0.0;
			for(i = 0; i < iDIM; ++i)
				inPoint_dot_n += inPoint[i]*n[i];
						
			double vPt0_dot_n = 0.0;
			for(i = 0; i < iDIM; ++i)
				vPt0_dot_n += m_pData[i] * n[i];

			for(i = 0; i < iDIM; ++i)
				outPoint[i] = inPoint[i] - (inPoint_dot_n - vPt0_dot_n) * n[i];

			// whether outPoint is inside the mesh or not
			double p3[iDIM];
			for(i = 0; i < iDIM; ++i)
				p3[i] = outPoint[i] - m_pData[i];

			double dot00 = p1[0] * p1[0] + p1[1] * p1[1] + p1[2] * p1[2];
			double dot01 = p1[0] * p2[0] + p1[1] * p2[1] + p1[2] * p2[2];
			double dot02 = p1[0] * p3[0] + p1[1] * p3[1] + p1[2] * p3[2];
			double dot11 = p2[0] * p2[0] + p2[1] * p2[1] + p2[2] * p2[2];
			double dot12 = p2[0] * p3[0] + p2[1] * p3[1] + p2[2] * p3[2];

			double denom = dot00 * dot11 - dot01 * dot01;
			double u = (dot11 * dot02 - dot01 * dot12) / denom;
			double v = (dot00 * dot12 - dot01 * dot02) / denom;

			return (u >= 0.0 && v >= 0.0 && u + v < 1.0 + ZERO_PRECISION) ? true : false; // inside
		}
		else
			return false;
	}

	bool CMesh::GetPointInLine(double* pPt1, double* pPt2, double* inPt, double* outPt)
	{
		int i;
		const int iDIM = CPointSet::DIM;

		double n[iDIM];
		for(i = 0; i < iDIM; ++i)
			n[i] = pPt2[i] - pPt1[i];

		double denorm = 0.0;
		for(i = 0; i < iDIM; ++i)
			denorm += n[i]*n[i];
		denorm = sqrt(denorm);

		if(denorm < ZERO_PRECISION) return false;

		for(int i = 0; i < iDIM; ++i)
			n[i] /= denorm;

		double w = 0.0;
		for(i = 0; i < iDIM; ++i)
			w += n[i] * (inPt[i] - pPt1[i]);

		for(i = 0; i < iDIM; ++i)
			outPt[i] = pPt1[i] + w * n[i];
		
		return (w/denorm > -ZERO_PRECISION && w/denorm < 1 + ZERO_PRECISION) ? true : false; // inside
	}

	//////////////////////////////////////////////////////////////////////////////
	// CMapPointToMesh
	//////////////////////////////////////////////////////////////////////////////
	CMapPointToMesh::CMapPointToMesh(int iNumMeshes, int* pMeshInform, const CPointSet& basePointSet)
	{
		m_iNumMeshes = iNumMeshes;
		m_iNumPoints = basePointSet.GetNumPoints();
		m_pMap = new deque<CMesh>[m_iNumPoints];

		int i, j;
		double* pPoints = new double[CMesh::DIM_MESH*CPointSet::DIM];
		CMesh* pTempMesh;

		// make map point to mesh
		for(i = 0; i < m_iNumMeshes; i++)
		{
			// *(pMeshInform+CMesh::DIM_MESH*i+j): index of point
			for(j = 0; j < CMesh::DIM_MESH; j++)
				memcpy(pPoints+CPointSet::DIM*j,
					basePointSet.GetPointSetRaw(*(pMeshInform+CMesh::DIM_MESH*i+j)),
					CPointSet::DIM*sizeof(double));
			
			pTempMesh = new CMesh(pPoints);
			for(j = 0; j < CMesh::DIM_MESH; j++)
				m_pMap[*(pMeshInform + CMesh::DIM_MESH*i+j)].push_back(*pTempMesh);
			delete pTempMesh;
		}
		delete [] pPoints;
	}

	CMapPointToMesh::~CMapPointToMesh()
	{
		if(m_pMap != NULL)
			delete [] m_pMap;
	}

	bool CMapPointToMesh::GetCorrMeshList(int iPointIndex, deque<CMesh> **listMeshes)
	{
		if(iPointIndex >= 0 && iPointIndex < m_iNumPoints)
		{
			*listMeshes = &m_pMap[iPointIndex];
			return true;
		}
		else
			return false;
	}

	//////////////////////////////////////////////////////////////////////////////
	// class CPointCloudbyANN
	//////////////////////////////////////////////////////////////////////////////
	CPointCloudbyANN::CPointCloudbyANN() 
	: m_nDataPts(0), m_arDataPts(NULL), m_pkdTree(NULL)
	{
	}

	CPointCloudbyANN::~CPointCloudbyANN()
	{
		if(m_arDataPts != NULL) annDeallocPts(m_arDataPts);
		if(m_pkdTree != NULL) delete m_pkdTree;
		annClose();
	}

	bool CPointCloudbyANN::SetDataPoints(CPointSet& points)
	{
		m_nDataPts = points.GetNumPoints();

		if(m_nDataPts <= 0) return false;

		m_nDIM = CPointSet::DIM;
		
		// memory assignment, coordinate values assignment
		m_arDataPts = annAllocPts(m_nDataPts,m_nDIM);
		for(int i = 0; i < m_nDataPts; ++i)
			memcpy(m_arDataPts[i],points.GetPointSetRaw(i),sizeof(ANNcoord)*m_nDIM);
		
		m_pkdTree = new ANNkd_tree(m_arDataPts,m_nDataPts,m_nDIM);

		return (m_pkdTree != NULL) ? true : false;
	}

	int CPointCloudbyANN::GetNearestPointIndex(double* queryPt, const int& dim, double &dist) const
	{
		if(dim == m_nDIM)
		{
			ANNpoint tQueryPt = annAllocPt(m_nDIM);
			memcpy(tQueryPt,queryPt,sizeof(double)*m_nDIM);
			
			ANNidxArray nnIdx = new ANNidx[1];
			ANNdistArray dists = new ANNdist[1];

			m_pkdTree->annkSearch(tQueryPt,1,nnIdx,dists);

			dist = dists[0];

			return nnIdx[0];
		}
		else
			return -1;
	}

	//////////////////////////////////////////////////////////////////////////////
	// class CReferenceModel
	//////////////////////////////////////////////////////////////////////////////
	CReferenceModel::CReferenceModel()
	{
		m_pRefPts = NULL;
		m_pMapPointToMesh = NULL;
		
		m_iNumPoints = 0;
		m_iNumMeshes = 0;
	}

	CReferenceModel::~CReferenceModel()
	{
		if(m_pRefPts != NULL)
			delete m_pRefPts;
		if(m_pMapPointToMesh != NULL)
			delete m_pMapPointToMesh;
	}

	bool CReferenceModel::LoadData(char* pFileName)
	{
		// load from "*.*TL"
		FILE* fp;
		fopen_s(&fp, pFileName, "r");
		if(fp == NULL) 
		{
			return false;
		}
		
		int i, iBuffer;
		int iBufferSize = 256;
		char* pCBuffer = new char[iBufferSize];
		memset(pCBuffer, 0, iBufferSize*sizeof(char));

		// skip until "*" line
 		while(pCBuffer[0] != '*')
		{
 			if(fgets(pCBuffer, iBufferSize, fp) == NULL)
			{
				return false;	// EOF
			}
		}

		/* Load file */
		// skip "filter size = *, t1 = *, t2 = *" line
		fgets(pCBuffer, iBufferSize, fp);
		if(pCBuffer != NULL)
		{
			delete [] pCBuffer;
			pCBuffer = NULL;
		}

		// read # of vertices, facets, and edges
		iBuffer = fscanf_s(fp, "%d %d %d\n", &m_iNumPoints, &m_iNumMeshes, &iBuffer);
		if(iBuffer != 3 || fp == NULL)
		{
			delete [] pCBuffer;
			pCBuffer = NULL;

			return false;
		}

		// read contents of vertices
		double* pPoints = new double[CPointSet::DIM * m_iNumPoints];
		if(pPoints == NULL) 
		{
			delete [] pCBuffer;
			pCBuffer = NULL;

			return false;
		}

		for(i = 0; i < m_iNumPoints; i++)
		{
			iBuffer = fscanf_s(fp, "%lf %lf %lf\n", pPoints+CPointSet::DIM*i, pPoints+CPointSet::DIM*i+1, pPoints+CPointSet::DIM*i+2);
			if(iBuffer != 3 || fp == NULL)
			{
				break;
			}
		}
		if(i == m_iNumPoints)
		{
			m_pRefPts = new CPointSet(m_iNumPoints, pPoints);
			m_kdTree.SetDataPoints(*m_pRefPts);
		}
		
		if(i < m_iNumPoints) 
		{
			return false;
		}

		// read contents of facets
		int* pMeshInform = new int[CMesh::DIM_MESH * m_iNumMeshes];
		if(pMeshInform == NULL) return false;

		for(i = 0; i < m_iNumMeshes; i++)
		{
			iBuffer = fscanf_s(fp, "%d %d %d %d %d\n",
				&iBuffer, pMeshInform+CMesh::DIM_MESH*i, pMeshInform+CMesh::DIM_MESH*i+1, pMeshInform+CMesh::DIM_MESH*i+2, &iBuffer);
			if(iBuffer != 5 || fp == NULL)
				break;
		}
		if(i == m_iNumMeshes)
		{
			m_pMapPointToMesh = new CMapPointToMesh(m_iNumMeshes, pMeshInform, *m_pRefPts);
		}

		LoadData(m_iNumPoints, pPoints, m_iNumMeshes, pMeshInform);

		delete [] pMeshInform;
		pMeshInform = NULL;
		delete [] pPoints;
		pPoints = NULL;

		if(i < m_iNumMeshes) 
		{
			return false;
		}
		
		fclose(fp);


		return true;
	}

	bool CReferenceModel::LoadDataSTL(char* pFileName)
	{
		std::ifstream stl_file(pFileName, std::ios::in | std::ios::binary);

		char header_info[80] = "";
		char n_triangles[4];
		stl_file.read(header_info, 80);
		stl_file.read(n_triangles, 4);

		unsigned int* r = (unsigned int*) n_triangles;
		unsigned int num_triangles = *r;

		m_iNumMeshes = (int) num_triangles;

		// read contents of vertices
		double* pPoints = new double[CPointSet::DIM * m_iNumMeshes]; // Still I don't know exactly, but m_iNumMeshes < m_iNumMeshes
		int* pMeshInform = new int[CMesh::DIM_MESH * m_iNumMeshes];

		int nPointCount = 0;
		int nMeshCount = 0;

		for (int i = 0; i < m_iNumMeshes; i++) 
		{
			// Normal
			for (int ijk = 0; ijk < 3; ijk++)
			{
				char f_buf[sizeof(float)];
				stl_file.read(f_buf, 4);
				int* fptr = (int*) f_buf;
				memset(pMeshInform+CMesh::DIM_MESH*nPointCount + ijk, *fptr, sizeof(int));
			}
			nMeshCount++;

			// v1
			for (int xyz = 0; xyz < 3; xyz++)
			{
				char f_buf[sizeof(float)];
				stl_file.read(f_buf, 4);
				double* fptr = (double*) f_buf;
				memset(pPoints+CPointSet::DIM*nPointCount + xyz, *fptr, sizeof(double));
			}
			nPointCount++;

			// v2
			for (int xyz = 0; xyz < 3; xyz++)
			{
				char f_buf[sizeof(float)];
				stl_file.read(f_buf, 4);
				double* fptr = (double*) f_buf;
				memset(pPoints+CPointSet::DIM*nPointCount + xyz, *fptr, sizeof(double));
			}
			nPointCount++;

			// v3
			for (int xyz = 0; xyz < 3; xyz++)
			{
				char f_buf[sizeof(float)];
				stl_file.read(f_buf, 4);
				double* fptr = (double*) f_buf;
				memset(pPoints+CPointSet::DIM*nPointCount + xyz, *fptr, sizeof(double));
			}
			nPointCount++;

			// Footer
			char dummy[2];
			stl_file.read(dummy, 2);
		}

		m_iNumPoints = nPointCount;
		/*m_pRefPts = new CPointSet(m_iNumPoints, pPoints);
		m_kdTree.SetDataPoints(*m_pRefPts);

		m_pMapPointToMesh = new CMapPointToMesh(m_iNumMeshes, pMeshInform, *m_pRefPts);*/

		LoadData(m_iNumPoints, pPoints, m_iNumMeshes, pMeshInform);

		delete [] pMeshInform;
		pMeshInform = NULL;
		delete [] pPoints;
		pPoints = NULL;
		
		stl_file.close();

		return true;
	}

	bool CReferenceModel::LoadDataOBJ(char* pFileName)
	{
		// load from "*.*TL"
		FILE* fp;
		fopen_s(&fp, pFileName, "r");
		if(fp == NULL) 
		{
			return false;
		}
		
		int i, iBuffer;
		int iBufferSize = 256;
		char* pCBuffer = new char[iBufferSize];
		memset(pCBuffer, 0, iBufferSize*sizeof(char));
		int iNubmerOfPoints = 0;

		fgets(pCBuffer, iBufferSize, fp);

		/* Load file */
		fgets(pCBuffer, iBufferSize, fp);
		sscanf(&pCBuffer[2], "%d", &m_iNumMeshes);

		// read contents of vertices
		double* pPoints = new double[CPointSet::DIM * m_iNumMeshes]; // Still I don't know exactly, but m_iNumMeshes < m_iNumMeshes
		int* pMeshInform = new int[CMesh::DIM_MESH * m_iNumMeshes];
		if(pPoints == NULL) 
		{
			delete [] pCBuffer;
			pCBuffer = NULL;

			return false;
		}

		if(pMeshInform == NULL) 
			return false;

		int nPointCount = 0;
		int nMeshCount = 0;
		while (fgets(pCBuffer, iBufferSize, fp) != NULL) // until the EOF
		{
			switch (pCBuffer[0])
			{
			case 'v':
				iBuffer = sscanf_s(&pCBuffer[2], "%lf %lf %lf\n", pPoints+CPointSet::DIM*nPointCount, pPoints+CPointSet::DIM*nPointCount+1, pPoints+CPointSet::DIM*nPointCount+2);
				nPointCount++;
				break;
			case 'f':
				iBuffer = sscanf_s(&pCBuffer[2], "%d %d %d\n", pMeshInform+CMesh::DIM_MESH*nMeshCount, pMeshInform+CMesh::DIM_MESH*nMeshCount+1, pMeshInform+CMesh::DIM_MESH*nMeshCount+2);
				*(pMeshInform+CMesh::DIM_MESH*nMeshCount + 0) -= 1;
				*(pMeshInform+CMesh::DIM_MESH*nMeshCount + 1) -= 1;
				*(pMeshInform+CMesh::DIM_MESH*nMeshCount + 2) -= 1;
				nMeshCount++;
				break;
			}
			
			if ((iBuffer != 3 || fp == NULL) || (nPointCount > m_iNumMeshes))
			{
				delete [] pCBuffer;
				delete [] pPoints;
				delete [] pMeshInform;

				return false;
			}
		}

		m_iNumPoints = nPointCount;
		/*m_pRefPts = new CPointSet(m_iNumPoints, pPoints);
		m_kdTree.SetDataPoints(*m_pRefPts);

		m_pMapPointToMesh = new CMapPointToMesh(m_iNumMeshes, pMeshInform, *m_pRefPts);*/

		LoadData(m_iNumPoints, pPoints, m_iNumMeshes, pMeshInform);

		delete [] pMeshInform;
		pMeshInform = NULL;
		delete [] pPoints;
		pPoints = NULL;
		
		fclose(fp);

		return true;
	}

	bool CReferenceModel::LoadData(int iNumPoints, double* pRefPts, int iNumMeshes, int* pMeshInform)
	{
		m_iNumPoints = iNumPoints;
		m_iNumMeshes = iNumMeshes;

		if(m_iNumPoints > 0 && m_iNumMeshes > 0 && pRefPts != NULL && pMeshInform != NULL)
		{
			m_pRefPts = new CPointSet(iNumPoints, pRefPts);
			m_kdTree.SetDataPoints(*m_pRefPts);
			m_pMapPointToMesh = new CMapPointToMesh(m_iNumMeshes, pMeshInform, *m_pRefPts);

			return true;
		}
		else
			return false;		
	}

	bool CReferenceModel::GetNearestPoint(double* inPoint, double& dist, double* outPoint)
	{
		int iPointIndex = m_kdTree.GetNearestPointIndex(inPoint, CPointSet::DIM, dist);

#if 0	// P2P data association
		memcpy(outPoint, m_pRefPts->GetPointSetRaw(iPointIndex), CPointSet::DIM*sizeof(double));
		dist = 0.0;
		for(int i = 0; i < CPointSet::DIM; i++)
			dist += (outPoint[i] - inPoint[i]) * (outPoint[i] - inPoint[i]);

		return true;
#endif

		// P2S data association
		deque<CMesh> *tListMeshes = NULL;
		m_pMapPointToMesh->GetCorrMeshList(iPointIndex, &tListMeshes);
		int iNumCorrMeshes = (int)tListMeshes->size();

		if(iNumCorrMeshes > 0)
		{
			int i;
			double* pTempArrDist = new double[iNumCorrMeshes];
			double* pTempPointSet = new double[CPointSet::DIM*iNumCorrMeshes];
			double tPoint[CPointSet::DIM];
			double* pPtr;

			auto it = tListMeshes->begin();
			for(i = 0; i < iNumCorrMeshes; i++, it++)
			{
				it->GetClosestPoint(inPoint, tPoint);
				memcpy(pTempPointSet+CPointSet::DIM*i, tPoint, CPointSet::DIM*sizeof(double));
			}

			CPointSet tCandPointSet(iNumCorrMeshes, pTempPointSet);
			tCandPointSet.GetDistArr(inPoint, pTempArrDist);

			pPtr = min_element(pTempArrDist, pTempArrDist+iNumCorrMeshes);
			memcpy(outPoint, tCandPointSet.GetPointSetRaw(pPtr-pTempArrDist), CPointSet::DIM*sizeof(double));
			dist = pTempArrDist[pPtr-pTempArrDist];

			delete [] pTempPointSet;
			delete [] pTempArrDist;

			return true;
		}
		else
			return false;
	}
}
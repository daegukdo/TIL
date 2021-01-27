/* 
@ LeetCode
4Sum II

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

ref : https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1134/
ref : https://stackoverflow.com/questions/40716694/how-to-improve-the-performance-of-leetcode-4sum-ii-challenge
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		// A[i] + B[j] + C[k] + D[l] = 0 -> A[i] + B[j] = -( C[k] + D[l] )
		// A와 B를 더해서 mapSumAB에 저장
		// C와 D를 더해서 mapSumCD에 저장
		// 각각의 map에서 하나씩 꺼내어 비교
		// map1의 값은 map2의 값의 마이너스랑 같다를 이용
				
		// prepare data
		unordered_map<int, int> mapSumAB;
		unordered_map<int, int> mapSumCD;

		for(auto iterA = A.begin(); iterA != A.end(); iterA++){
			for(auto iterB = B.begin(); iterB != B.end(); iterB++){
				int tmpInt = *iterA + *iterB;
				auto elm = mapSumAB.find(tmpInt);
				if(elm != mapSumAB.end()){
					elm->second += 1;
				}
				else{
					mapSumAB.insert(make_pair(tmpInt, 1));
				}
			}
		}
		
		for(auto iterC = C.begin(); iterC != C.end(); iterC++){
			for(auto iterD = D.begin(); iterD != D.end(); iterD++){
				int tmpInt = *iterC + *iterD;
				auto elm = mapSumCD.find(tmpInt);
				if(elm != mapSumCD.end()){
					elm->second += 1;
				}
				else{
					mapSumCD.insert(make_pair(tmpInt, 1));
				}
			}
		}

		// cal. result
        int rst = 0;

		for(auto iterAB = mapSumAB.begin(); iterAB != mapSumAB.end(); iterAB++){
			for(auto iterCD = mapSumCD.begin(); iterCD != mapSumCD.end(); iterCD++){
				if((iterAB->first) == -(iterCD->first)){
					rst++;
				}
			}
		}

		return rst;
    }
};

int main() {
	int A[2] = {  1,  2}; vector<int> vctA(begin(A), end(A));
	int B[2] = { -2, -1}; vector<int> vctB(begin(B), end(B));
	int C[2] = { -1,  2}; vector<int> vctC(begin(C), end(C));
	int D[2] = {  0,  2}; vector<int> vctD(begin(D), end(D));

	Solution sol;

	int rst = sol.fourSumCount(vctA, vctB, vctC, vctD);

	return 0;
}

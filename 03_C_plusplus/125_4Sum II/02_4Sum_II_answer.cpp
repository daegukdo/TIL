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
ref : https://www.lexicodes.com/articles/4sum-ii-cpp/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> sums;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				sums[A[i] + B[j]]++;
			}
		}

		int count = 0;
		for (int i = 0; i < C.size(); i++) {
			for (int j = 0; j < D.size(); j++) {
				if (sums.find(-(C[i] + D[j])) != sums.end()) {
					count += sums[-(C[i] + D[j])];
				}
			}
		}

		return count;
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
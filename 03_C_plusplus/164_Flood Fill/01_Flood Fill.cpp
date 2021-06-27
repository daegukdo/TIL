/*
@ LeetCode - Flood Fill

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. 

You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, 
plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 

Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.


Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel),
all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.


Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
 

Constraints:
m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n

Hide Hint #1  
Write a recursive function that paints the pixel if it's the correct color, then recurses on neighboring pixels.

ref : https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1393/
*/

#include <iostream>  
#include <vector> 

using namespace std;

class Solution {
private:
	vector<vector<int>> _floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int trgColor) {
		int imageCmin = 0;
		int imageRmin = 0;
		int imageCmax = image[0].size();
		int imageRmax = image.size();
		
		image[sr][sc] = newColor;

		if((imageRmin <= sr - 1) && (image[sr - 1][sc] == trgColor)){
			// up
			_floodFill(image, sr - 1, sc, newColor, trgColor);
		}
		if((imageCmin <= sc - 1) && (image[sr][sc - 1] == trgColor)){
			// left
			_floodFill(image, sr, sc - 1, newColor, trgColor);
		}
		if((imageRmax > sr + 1) && (image[sr + 1][sc] == trgColor)){
			// down
			_floodFill(image, sr + 1, sc, newColor, trgColor);
		}
		if((imageCmax > sc + 1) && (image[sr][sc + 1] == trgColor)){
			// right
			_floodFill(image, sr, sc + 1, newColor, trgColor);
		}

		return image;
	}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // pseudocode
		// sr, sc의 값을 찾기
		// 상하좌우로 값을 비교
		// 같다면 다시 sr, sc를 이 위치로 바꾸어서 recursive
		// DFS 방식 차용

		return _floodFill(image, sr, sc, newColor, image[sr][sc]);
    }
};

int main() {
	// q1
	/*vector<int> r0;
	r0.push_back(1);
	r0.push_back(1);
	r0.push_back(1);
	vector<int> r1;
	r1.push_back(1);
	r1.push_back(1);
	r1.push_back(0);
	vector<int> r2;
	r2.push_back(1);
	r2.push_back(0);
	r2.push_back(1);

	vector<vector<int>> img;
	img.push_back(r0);
	img.push_back(r1);
	img.push_back(r2);*/

	//q2
	vector<int> r0;
	r0.push_back(0);
	r0.push_back(0);
	r0.push_back(0);
	vector<int> r1;
	r1.push_back(0);
	r1.push_back(1);
	r1.push_back(1);

	vector<vector<int>> img;
	img.push_back(r0);
	img.push_back(r1);

	Solution sol;

	vector<vector<int>> rst = sol.floodFill(img, 1, 1, 1);

    return 0;
}

#include <iostream>  
#include <vector> 

using namespace std;

class Solution {
private:
	vector<vector<int>> visited;

	vector<vector<int>> _floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int trgColor) {
		visited[sr][sc] = 1;

		int imageCmin = 0;
		int imageRmin = 0;
		int imageCmax = image[0].size();
		int imageRmax = image.size();
		
		image[sr][sc] = newColor;

		if((imageRmin <= sr - 1) && (image[sr - 1][sc] == trgColor)){
			// up
			if(visited[sr - 1][sc] == 0)
			    _floodFill(image, sr - 1, sc, newColor, trgColor);
		}
		if((imageCmin <= sc - 1) && (image[sr][sc - 1] == trgColor)){
			// left
			if(visited[sr][sc - 1] == 0)
			    _floodFill(image, sr, sc - 1, newColor, trgColor);
		}
		if((imageRmax > sr + 1) && (image[sr + 1][sc] == trgColor)){
			// down
			if(visited[sr + 1][sc] == 0)
			    _floodFill(image, sr + 1, sc, newColor, trgColor);
		}
		if((imageCmax > sc + 1) && (image[sr][sc + 1] == trgColor)){
			// right
			if(visited[sr][sc + 1] == 0)
			    _floodFill(image, sr, sc + 1, newColor, trgColor);
		}

		return image;
	}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		for(int r = 0; r < image.size(); r++){
			vector<int> tmpRow;
			for(int c = 0; c < image[0].size(); c++){
				tmpRow.push_back(0);
			}
			visited.push_back(tmpRow);
		}

		return _floodFill(image, sr, sc, newColor, image[sr][sc]);
    }
};
// c++ code-war
/*
@ issue description

Pick peaks

@ Description

In this kata, you will write a function that returns the positions and the values of the "peaks" (or local maxima) of a numeric array.

For example, the array arr = [0, 1, 2, 5, 1, 0] has a peak at position 3 with a value of 5 (since arr[3] equals 5).

The output will be returned as an object of type PeakData which has two members: pos and peaks. 

Both of these members should be vector<int>s. 

If there is no peak in the given array then the output should be a PeakData with an empty vector for both the pos and peaks members.

PeakData is defined in Preloaded as follows:

struct PeakData {
  vector<int> pos, peaks;
};
Example: pickPeaks([3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3]) should return {pos: [3, 7], peaks: [6, 3]} (or equivalent in other languages)

All input arrays will be valid integer arrays (although it could still be empty), so you won't need to validate the input.

The first and last elements of the array will not be considered as peaks (in the context of a mathematical function, 
we don't know what is after and before and therefore, we don't know if it is a peak or not).

Also, beware of plateaus !!! [1, 2, 2, 2, 1] has a peak while [1, 2, 2, 2, 3] does not. 

In case of a plateau-peak, please only return the position and value of the beginning of the plateau. 

For example: pickPeaks([1, 2, 2, 2, 1]) returns {pos: [1], peaks: [2]} (or equivalent in other languages)

Have fun!
*/

#include <iostream>
#include <vector>

using namespace std;

struct PeakData
{
	vector<int> pos, peaks;
};

PeakData pick_peaks(vector<int> v);

int main()
{
	int arr1[] = { 1, 2, 1, 7, 6, 13, 13, 12, 14, 14, 19, 19, 18, 20, 20, 10 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
  
    vector<int> v1(arr1, arr1 + n1); 

	PeakData r1 = pick_peaks(v1);

	return 0;
}

PeakData pick_peaks(vector<int> v)
{
	vector<int> vDiff;

	for(int i = 0; i < v.size() - 1; i++)
	{
		vDiff.push_back(v[i + 1] - v[i]);
	}

	PeakData result;

	for(int i = 0; i < vDiff.size() - 1; i++)
	{
		if(vDiff[i] > 0 && vDiff[i + 1] < 0)
		{
			result.pos.push_back(i + 1);
			result.peaks.push_back(v[i + 1]);
		}

		if(vDiff[i] > 0 && vDiff[i + 1] == 0)
		{
			int j = 2;

			while(true)
			{
				if(vDiff[i] > 0 && vDiff[i + j] > 0)
				{
					break;
				}

				if(vDiff[i] > 0 && vDiff[i + j] < 0 && vDiff[i + j - 1] == 0)
				{
					result.pos.push_back(i + 1);
					result.peaks.push_back(v[i + 1]); 
					break;
				}

				j++;
			}
		}
	}

	return result;
}
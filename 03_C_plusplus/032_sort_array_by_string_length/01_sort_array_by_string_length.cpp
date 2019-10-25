// c++ code-war
/*
issue description

Write a function that takes an array of strings as an argument and returns a sorted array containing the same strings, ordered from shortest to longest.

For example, if this array were passed as an argument:

["Telescopes", "Glasses", "Eyes", "Monocles"]

Your function would return the following array:

["Eyes", "Glasses", "Monocles", "Telescopes"]

All of the strings in the array passed to your function will be different lengths, so you will not have to decide how to order multiple strings of the same length.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Kata
{
public:
    std::vector<std::string> sortByLength(std::vector<std::string> array)
    {
		int arraySize = array.size();
		int* lengthArray = new int[arraySize];
		int* sortedLengthArray = new int[arraySize];

		for(int i = 0; i<arraySize; i++)
		{
			lengthArray[i] = array[i].length();
		}

		for(int i = 0; i<arraySize; i++)
		{
			int count = 0;

			for(int j = 0; j<arraySize; j++)
			{
				if(lengthArray[i] > lengthArray[j])
				{
					count++;
				}
			}

			sortedLengthArray[i] = count;
		}

		std::vector <std::string> sortedArray(arraySize);

		for(int i = 0; i<arraySize; i++)
		{
			sortedArray[sortedLengthArray[i]] = array[i];
		}

		delete lengthArray;
		delete sortedLengthArray;

        return sortedArray;
    }
};

int main()
{
	// Declaring Vector of String type 
    vector <string> colour; 
  
    // Initialize vector with strings using push_back  
    // command 
    colour.push_back("Blue"); 
    colour.push_back("Red"); 
    colour.push_back("Orange"); 

	Kata a;

	vector <string> sortedcolour = a.sortByLength(colour); 

	for (int i=0; i<sortedcolour.size(); i++)     
        cout << sortedcolour[i] << "\n";  

	return 0;
}

// c++ code-war
/*
issue description

Input:

a string strng
an array of strings arr
Output of function contain_all_rots(strng, arr) (or containAllRots or contain-all-rots):

a boolean true if all rotations of strng are included in arr (C returns 1)
false otherwise (C returns 0)
Examples:
contain_all_rots(
  "bsjq", ["bsjq", "qbsj", "sjqb", "twZNsslC", "jqbs"]) -> true

contain_all_rots(
  "Ajylvpy", ["Ajylvpy", "ylvpyAj", "jylvpyA", "lvpyAjy", "pyAjylv", "vpyAjyl", "ipywee"]) -> false)
Note:
Though not correct in a mathematical sense

we will consider that there are no rotations of strng == ""
and for any array arr: contain_all_rots("", arr) --> true
Ref: https://en.wikipedia.org/wiki/String_(computer_science)#Rotations
*/

#include <string>
#include <vector>

using namespace std;

class Rotations
{
public:
    static bool containAllRots(const std::string &strng, std::vector<std::string> &arr);
};

bool Rotations::containAllRots(const std::string &strng, std::vector<std::string> &arr)
{
	bool isContained = false;

	int strLength = strng.length();

	string str = strng;
	string temp = "";

	int countRots = 0;

	for(int i = 0; i<strLength; i++)
	{
		std::rotate(str.begin(), str.begin() + 1, str.end()); 

		temp = str;

		if(std::find(arr.begin(), arr.end(), temp) != arr.end())
		{
			countRots++;
		}
	}

	if(countRots >= strLength)
	{
		isContained = true;
	}

	return isContained;
}

int main()
{
	std::string s1 = "bsjq";
	std::string s1array[5] = {"bsjq", "qbsj", "sjqb", "twZNsslC", "jqbs"};

    std::vector<std::string> v1(s1array, s1array + sizeof s1array / sizeof s1array[0]);

	std::string s2 = "XjYABhR";
	std::string s2array[8] = {"TzYxlgfnhf", "yqVAuoLjMLy", "BhRXjYA", "YABhRXj", "hRXjYAB", "jYABhRX", "XjYABhR", "ABhRXjY"};

    std::vector<std::string> v2(s2array, s2array + sizeof s2array / sizeof s2array[0]);

	std::string s3 = "Ajylvpy";
	std::string s3array[7] = {"Ajylvpy", "ylvpyAj", "jylvpyA", "lvpyAjy", "pyAjylv", "vpyAjyl", "ipywee"};

    std::vector<std::string> v3(s3array, s3array + sizeof s3array / sizeof s3array[0]);

	bool t1 = Rotations::containAllRots(s1, v1);
	bool t2 = Rotations::containAllRots(s2, v2);
	bool t3 = Rotations::containAllRots(s3, v3);

	return 0;
}
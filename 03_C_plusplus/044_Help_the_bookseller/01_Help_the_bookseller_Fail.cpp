// c++ code-war
/*
issue description

Help the bookseller !

A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more capitals letters. 

The 1st letter of a code is the capital letter of the book category. 

In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.

For example an extract of one of the stocklists could be:

L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
or

L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....
You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :

  M = {"A", "B", "C", "W"} 
or

  M = ["A", "B", "C", "W"] or ...
and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category.

For the lists L and M of example you have to return the string (in Haskell/Clojure/Racket a list of pairs):

  (A : 20) - (B : 114) - (C : 50) - (W : 0)
where A, B, C, W are the categories, 20 is the sum of the unique book of category A, 114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W.

If L or M are empty return string is "" (Clojure and Racket should return an empty array/list instead).

Note:
In the result codes and their values are in the same order as in M.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StockList
{
public:
	static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories);
};

std::string StockList::stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
{
	// 변수 정의
	string result = "";
	int numOfBooks = lstOfArt.capacity();
	int numOfCtgr = categories.capacity();

	if(numOfBooks == 0 || numOfCtgr == 0)
	{
		return "";
	}

	string *bookCptlArr = new string[numOfBooks];  
	int *bookCodeArr = new int[numOfBooks];
	string *ctgrArr = new string[numOfCtgr];
	int *ctgrCodeSumArr = new int[numOfCtgr];
	
	// 책의 첫번째 글자와 그 숫자를 나누는 작업
	string tmpStr1 = "";
	string tmpStr2 = "";
	int tmpInt1 = 0;
	int tmpInt2 = 0;

	for(int i = 0; i < numOfBooks; i++)
	{
		tmpStr1 = lstOfArt[i];
		bookCptlArr[i] = tmpStr1[0];

		tmpInt2 = tmpStr1.length();

		for(int j = tmpInt2 - 1; j > 0; j--)
		{
			if(tmpStr1[j] == ' ')
			{
				tmpInt1 = j;
			}
		}

		tmpStr2 = "";

		for(int k = tmpInt1; k < tmpStr1.length(); k++)
		{
			tmpStr2 += tmpStr1[k];
		}

		bookCodeArr[i] = stoi(tmpStr2);
	}

	// 카테고리의 글자를 추출 및 초기화
	for(int i = 0; i < numOfCtgr; i++)
	{
		ctgrArr[i] = categories[i];
		ctgrCodeSumArr[i] = 0;
	}

	// 카테고리의 글자와 책의 첫번째 글자가 같은 것들을 모두 저장
	for(int i = 0; i < numOfCtgr; i++)
	{
		for(int j = 0; j < numOfBooks; j++)
		{
			if(ctgrArr[i] == bookCptlArr[j])
			{
				ctgrCodeSumArr[i] += bookCodeArr[j];
			}
		}
	}

	// 이후 특정한 포맷으로 string 값을 리턴
	// ex ... (A : 20) - (B : 114) - (C : 50) - (W : 0)
	for(int i = 0; i < numOfCtgr; i++)
	{
		if(ctgrArr[i].size() != 0)
		{
			result += "(" + ctgrArr[i] + " : " + to_string(ctgrCodeSumArr[i]) + ")";

			if(i < numOfCtgr - 1)
			{
				if(ctgrArr[i+1].size() != 0)
				{
					result += " - ";
				}
			}
		}
	}

	// 마무리
	delete[] bookCptlArr;  
	delete[] bookCodeArr;
	delete[] ctgrArr;
	delete[] ctgrCodeSumArr;

	return result;
}

int main()
{
	string arr1[] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    vector<string> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );

	string arr2[] = {"A", "B", ""};
    vector<string> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

	string a = StockList::stockSummary(vec1, vec2);

	return 0;
}
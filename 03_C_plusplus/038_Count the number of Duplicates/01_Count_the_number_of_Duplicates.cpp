// c++ code-war
/*
issue description

Count the number of Duplicates
Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. 
The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

Example
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice
*/

#include<string>

size_t duplicateCount(const char* in);
//size_t duplicateCount(const std::string& in); // helper for tests
std::string removeCharInStr(std::string targetStr, char inputChar);

int main()
{
	char* a = "aabBcde";
	size_t r = duplicateCount(a);
	return 0;
}

size_t duplicateCount(const char* in)
{
	std::string input = "";

	int lengthOfString = strlen(in);
	int resultOfDuplicateCount = 0;
	int count = 0;

	for(int i = 0; i < lengthOfString; i++)
	{
		input += toupper(in[i]);
	}

	while(lengthOfString != 0)
	{
		count = 0;

		for(int i = 0; i < lengthOfString; i++)
		{
			if(input[0] == input[i])
			{
				count++;
			}
		}

		if(count >= 2)
		{
			resultOfDuplicateCount++;
		}

		input = removeCharInStr(input, input[0]);

		lengthOfString = input.length();
	}

	return resultOfDuplicateCount;
}

std::string removeCharInStr(std::string targetStr, char inputChar)
{
	std::string result = "";

	int lengthOfStr = targetStr.length();

	for(int i = 0; i < lengthOfStr; i++)
	{
		if(inputChar != targetStr[i])
		{
			result += targetStr[i];
		}
	}

	return result;
}

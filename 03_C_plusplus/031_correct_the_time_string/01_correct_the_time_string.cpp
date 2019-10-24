// c++ code-war
/*
issue description

A new task for you!

You have to create a method, that corrects a given time string. There was a problem in addition, so many of the time strings are broken. Time-Format is european. So from "00:00:00" to "23:59:59".

Some examples:

"09:10:01" -> "09:10:01"
"11:70:10" -> "12:10:10"
"19:99:99" -> "20:40:39"
"24:01:01" -> "00:01:01"

If the input-string is null or empty return exactly this value! (empty string for C++)
If the time-string-format is invalid, return null. (empty string for C++)

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have created other katas. Have a look if you like coding and challenges.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

std::string correct(std::string timeString);

int main()
{
	string a = correct("19:99:99");
	return 0;
}

std::string correct(std::string timeString)
{ 
	std::string correctedTimeStr = "";

	std::string timeStringData = timeString;
	int timeStringDataLength = timeStringData.length();

	std::string delimiter = ":";

	int formatchecker = 0;

	for(int i = 0; i<timeStringDataLength; i++)
	{
		if(timeStringData[i] == delimiter[0])
		{
			formatchecker++;
		}

		int temp = timeStringData[i] - 48;

		if(!(temp >= 0 && temp <= 9))
		{
			if(temp != 10)
			{
				return "";
			}
		}
	}

	if(formatchecker != 2 || timeStringDataLength != 8)
	{
		return "";
	}

	int hourMinScd = 3;
	int* timeChunk = new int[hourMinScd];
	size_t pos = timeStringData.find(delimiter);

	int count = 0;

	while (count < hourMinScd) 
	{
		timeChunk[count] = std::stoi(timeStringData.substr(0, pos));
		count++;
		timeStringData.erase(0, pos + delimiter.length());
	}

	for(int i = (hourMinScd-1); i>=0; i--)
	{
		if(i - 1 >= 0)
		{
			if(timeChunk[i] >= 60)
			{
				timeChunk[i-1] = (timeChunk[i-1] + 1);
				timeChunk[i] = (timeChunk[i] - 60);
			}
		}
		else
		{
			if(timeChunk[i] >= 24)
			{
				while(timeChunk[i] >= 24)
				{
					timeChunk[i] = timeChunk[i] - 24;
				}
			}
		}
	}

	for(int i = 0; i<hourMinScd; i++)
	{
		std::stringstream strStream;

		strStream << "";

		strStream << std::setw(2) << std::setfill('0') << timeChunk[i];

		correctedTimeStr += strStream.str();

		if(i < hourMinScd-1)
		{
			correctedTimeStr += delimiter;
		}
	}

    return correctedTimeStr;
}

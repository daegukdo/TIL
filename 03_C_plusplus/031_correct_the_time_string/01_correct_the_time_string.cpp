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
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */

using namespace std;

std::string correct(std::string timeString);

int main()
{

	return 0;
}

std::string correct(std::string timeString)
{ 
	std::string correctedTimeStr = "";

	std::string timeStringData = timeString;

	int hourMinScd = 3;
	size_t pos = 0;
	std::string* timeChunk = new string[hourMinScd];
	std::string delimiter = ":";

	int count = 0;

	while ((pos = timeStringData.find(delimiter)) != std::string::npos) 
	{
		timeChunk[count] = timeStringData.substr(0, pos);
		count++;
		timeStringData.erase(0, pos + delimiter.length());
	}

	for(int i = (hourMinScd-1); i>-0; i--)
	{
		int temp = std::stoi(timeChunk[i]);
	}

    return "?";
}

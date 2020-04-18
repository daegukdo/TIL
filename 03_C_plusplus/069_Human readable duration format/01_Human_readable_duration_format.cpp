// c++ code-war
/*
@ issue description

Human readable duration format

@ Description

Your task in order to complete this Kata is to write a function which formats a duration, 
given as a number of seconds, in a human-friendly way.

The function must accept a non-negative integer. 
If it is zero, it just returns "now". 
Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

format_duration(62)    // returns "1 minute and 2 seconds"
format_duration(3662)  // returns "1 hour, 1 minute and 2 seconds"
For the purpose of this Kata, a year is 365 days and a day is 24 hours.

Note that spaces are important.

Detailed rules
The resulting expression is made of components like 4 seconds, 1 year, etc. 
In general, a positive integer and one of the valid units of time, separated by a space. 
The unit of time is used in plural if the integer is greater than 1.

The components are separated by a comma and a space (", "). 
Except the last component, which is separated by " and ", just like it would be written in English.

A more significant units of time will occur before than a least significant one. 
Therefore, 1 second and 1 year is not correct, but 1 year and 1 second is.

Different components have different unit of times. 
So there is not repeated units like in 5 seconds and 1 second.

A component will not appear at all if its value happens to be zero. 
Hence, 1 minute and 0 seconds is not valid, but it should be just 1 minute.

A unit of time must be used "as much as possible". 
It means that the function should not return 61 seconds, but 1 minute and 1 second instead. 
Formally, the duration specified by of a component must not be greater than any valid more significant unit of time.
*/

#include <string>
using namespace std;

std::string format_duration(int seconds);

int main()
{
	/*
    Assert::That(format_duration(0), Equals("now"));
    Assert::That(format_duration(1), Equals("1 second"));       
    Assert::That(format_duration(62), Equals("1 minute and 2 seconds"));
    Assert::That(format_duration(120), Equals("2 minutes"));
    Assert::That(format_duration(3662), Equals("1 hour, 1 minute and 2 seconds"));
	*/
	
	string r0 = format_duration(0);
	string r1 = format_duration(1);
	string r2 = format_duration(62);
	string r3 = format_duration(120);
	string r4 = format_duration(3662);

	return 0;
}

std::string format_duration(int seconds)
{
	//// define and setup variable
	int minutesUnitBySecond = 60;
	int hourUnitBySecond = minutesUnitBySecond * 60;
	int dayUnitBySecond = hourUnitBySecond *24;
	int yearUnitBySecond = dayUnitBySecond * 365;

	int second = 0;
	int minute = 0;
	int hour = 0;
	int day = 0;
	int year = 0;

	int temp_portion = 0;
	int temp_rest = 0;

	//// cal. each time value to variable
	// set year value
	temp_portion = seconds / yearUnitBySecond;
	temp_rest = seconds % yearUnitBySecond;

	if(temp_portion > 0)
	{
		year = temp_portion;
	}

	// set day value
	temp_portion = temp_rest / dayUnitBySecond;
	temp_rest = temp_rest % dayUnitBySecond;

	if(temp_portion > 0)
	{
		day = temp_portion;
	}

	// set hour value
	temp_portion = temp_rest / hourUnitBySecond;
	temp_rest = temp_rest % hourUnitBySecond;

	if(temp_portion > 0)
	{
		hour = temp_portion;
	}

	// set minute value
	temp_portion = temp_rest / minutesUnitBySecond;
	temp_rest = temp_rest % minutesUnitBySecond;

	if(temp_portion > 0)
	{
		minute = temp_portion;
	}

	// set second value
	second = temp_rest;

	//// set data that export to string	
	string timeDataStr[] = {"year", "day", "hour", "minute", "second"};
	int timeData[] = {year, day, hour, minute, second};
	int isHaveValueCount = 0;

	for(int i = 0; i < 5; i++)
	{
		if(timeData[i] > 0)
		{
			isHaveValueCount++;
		}
	}
	
	int tempCount = 0;
	std::string resultStr = "";
	
	switch(isHaveValueCount)
	{
		case 0:
			return "now";
			break;
		case 1:
			for(int i = 0; i < 5; i++)
			{
				int tempInt = timeData[i];
				if(timeData[i] > 0)
				{
					resultStr =  to_string(timeData[i]) + " " + timeDataStr[i];
					if(timeData[i] == 1)
					{
						return (resultStr);
					}
					else
					{
						return (resultStr + "s");
					}
				}
			}
			break;
		case 2:
			for(int i = 0; i < 5; i++)
			{
				int tempInt = timeData[i];
				if(timeData[i] > 0)
				{
					resultStr = resultStr + to_string(timeData[i]) + " " + timeDataStr[i];
					if(timeData[i] > 1)
					{
						resultStr = resultStr + "s";
					}
					if(tempCount == 0)
					{
						resultStr = resultStr + " and ";
					}
					tempCount++;
				}
			}
			return resultStr;
			break;
		case 3:
			for(int i = 0; i < 5; i++)
			{
				int tempInt = timeData[i];
				if(timeData[i] > 0)
				{
					resultStr = resultStr + to_string(timeData[i]) + " " + timeDataStr[i];
					if(timeData[i] > 1)
					{
						resultStr = resultStr + "s";
					}
					if(tempCount == 1)
					{
						resultStr = resultStr + " and ";
					}
					else
					{
						resultStr = resultStr + ", ";
					}
					tempCount++;
				}
			}
			return resultStr;
			break;
		case 4:
			for(int i = 0; i < 5; i++)
			{
				int tempInt = timeData[i];
				if(timeData[i] > 0)
				{
					resultStr = resultStr + to_string(timeData[i]) + " " + timeDataStr[i];
					if(timeData[i] > 1)
					{
						resultStr = resultStr + "s";
					}
					if(tempCount == 2)
					{
						resultStr = resultStr + " and ";
					}
					else
					{
						resultStr = resultStr + ", ";
					}
					tempCount++;
				}
			}
			return resultStr;
			break;
		case 5:
			for(int i = 0; i < 5; i++)
			{
				int tempInt = timeData[i];
				if(timeData[i] > 0)
				{
					resultStr = resultStr + to_string(timeData[i]) + " " + timeDataStr[i];
					if(timeData[i] > 1)
					{
						resultStr = resultStr + "s";
					}
					if(tempCount == 3)
					{
						resultStr = resultStr + " and ";
					}
					else
					{
						resultStr = resultStr + ", ";
					}
					tempCount++;
				}
			}
			return resultStr;
			break;
		default:
			// nothing
			break;
	}
}
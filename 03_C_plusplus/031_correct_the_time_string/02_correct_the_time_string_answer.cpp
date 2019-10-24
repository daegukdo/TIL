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

#include <regex>
#include <string>

std::string correct(std::string timeString)
{ 
  if (timeString.empty())
    return timeString;
  std::regex reg("(\\d\\d):(\\d\\d):(\\d\\d)");
  std::cmatch cm;
  if (std::regex_match(timeString.c_str(), cm, reg)) {
    int hours = atoi(cm[1].first);
    int minutes = atoi(cm[2].first);
    int seconds = atoi(cm[3].first);
    minutes += seconds / 60;
    hours += minutes / 60;
    seconds %= 60;
    minutes %= 60;
    hours %= 24; 

    char result[9];    
    sprintf(result, "%02d:%02d:%02d", hours, minutes, seconds);
    return std::string(result);
  }
  return "";
}
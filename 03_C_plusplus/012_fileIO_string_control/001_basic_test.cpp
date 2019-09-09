#include <iostream>
#include <fstream>

#include <string>


int main()
{
	int countLine = 0;

	std::ifstream data("data.txt");

	std::string line = "";

	std::string delimiter = ",";
	
	std::string value = "";

	size_t pos = 0;

	if(data.is_open())
	{
		while(data.good())
		{
			std::getline(data, line);
			std::cout << line << std::endl;
			countLine++;

			while ((pos = line.find(delimiter)) != std::string::npos) 
			{
				value = line.substr(0, pos);
				std::cout << value << std::endl;
				line.erase(0, pos + delimiter.length());
			}

			std::cout << line << std::endl;
		}
	}
	else
	{
		std::cout << "nope" << std::endl;
	}
	
	data.close();

	std::cout << countLine << std::endl;

	return 0;
}
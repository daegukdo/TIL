// c++ code-war
/*
@ issue description

RGB To Hex Conversion

@ Description

The rgb function is incomplete. 

Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. 

Valid decimal values for RGB are 0 - 255. 

Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
*/

#include <string>
using namespace std;

class RGBToHex
{
private:
	static std::string dec2hexOneDigit(int dec);
	static std::string dec2hexOneColor(int dec);

public:
	static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::dec2hexOneDigit(int dec)
{
	if(dec < 10)
	{
		return to_string(dec);
	}
	else
	{
		int tmpInt = dec - 10;

		string tmpStr(1, char(65 + tmpInt));

		return tmpStr;
	}
}

std::string RGBToHex::dec2hexOneColor(int dec)
{
	int hex = 16;

	int inputInt = dec;

	if(dec > 255)
	{
		inputInt = 255;
	}
	else if(dec < 0)
	{
		inputInt = 0;
	}

	return dec2hexOneDigit(inputInt / hex) + dec2hexOneDigit(inputInt % hex);
}

std::string RGBToHex::rgb(int r, int g, int b)
{
	// decimal to hex
	int hex = 16;

	string rHex = dec2hexOneColor(r);
	string gHex = dec2hexOneColor(g);
	string bHex = dec2hexOneColor(b);

	return rHex + gHex + bHex;
}

int main()
{
	std::string r1 = RGBToHex::rgb(-20,275,125);
	std::string r2 = RGBToHex::rgb(255, 255, 255);
	std::string r3 = RGBToHex::rgb(148, 0, 211);

	return 0;
}
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
  public:
  static std::string decToHex(int input) {
    std::string output = "00";
    std::string chars_for_hex = "0123456789ABCDEF";

    if(input < 0) input=0;
    if(input > 255) input = 255;

    output[1] = chars_for_hex[(input % 16)];
    input >>= 4; 
    output[0] = chars_for_hex[(input % 16)];

  return output;
}

  static std::string rgb(int r, int g, int b) {
    return decToHex(r) + decToHex(g) + decToHex(b);
  }
};

int main()
{
	std::string r1 = RGBToHex::rgb(-20,275,125);
	std::string r2 = RGBToHex::rgb(255, 255, 255);
	std::string r3 = RGBToHex::rgb(148, 0, 211);

	return 0;
}
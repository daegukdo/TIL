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

#include <sstream>
#include <iomanip>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b)
{
  std::ostringstream oss;
  oss << std::uppercase << std::setfill('0') << std::hex
      << std::setw(2) << (r < 0 ? 0 : r > 255 ? 255 : r)
      << std::setw(2) << (g < 0 ? 0 : g > 255 ? 255 : g)
      << std::setw(2) << (b < 0 ? 0 : b > 255 ? 255 : b);
  return oss.str();
}

int main()
{
	std::string r1 = RGBToHex::rgb(-20,275,125);
	std::string r2 = RGBToHex::rgb(255, 255, 255);
	std::string r3 = RGBToHex::rgb(148, 0, 211);

	return 0;
}
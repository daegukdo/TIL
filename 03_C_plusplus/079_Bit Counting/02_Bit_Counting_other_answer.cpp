/* 
@ issue description
Bit Counting

Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary representation of that number. 

You can guarantee that input is non-negative.

Example: 

The binary representation of 1234 is 10011010010, so the function should return 5 in this case
*/

#include <limits>
#include <bitset>

int main() 
{
	unsigned int t1 = countBits(1234);

	return 0;
}

inline constexpr unsigned int countBits(const unsigned long long n) noexcept {
  std::bitset<std::numeric_limits<unsigned long long>::digits> b(n);
  return b.count();
}
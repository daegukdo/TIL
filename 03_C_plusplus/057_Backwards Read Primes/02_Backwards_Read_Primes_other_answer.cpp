// c++ code-war
/*
issue description

Backwards Read Primes

Description

Backwards Read Primes are primes that when read backwards in base 10 (from right to left) are a different prime. (This rules out primes which are palindromes.)

Examples:
13 17 31 37 71 73 are Backwards Read Primes
13 is such because it's prime and read from right to left writes 31 which is prime too. Same for the others.

Task
Find all Backwards Read Primes between two positive given numbers (both inclusive), the second one always being greater than or equal to the first one. 

The resulting array or the resulting string will be ordered following the natural order of the prime numbers.

Example
backwardsPrime(2, 100) => [13, 17, 31, 37, 71, 73, 79, 97] backwardsPrime(9900, 10000) => [9923, 9931, 9941, 9967] backwardsPrime(501, 599) => []

Note for Forth
Return only the first backwards-read prime between start and end or 0 if you don't find any

backwardsPrime(2, 100) => "13 17 31 37 71 73 79 97"
backwardsPrime(9900, 10000) => "9923 9931 9941 9967"
*/

#include <cmath>

using namespace std;
typedef long long ll;

class BackWardsPrime {
 public:
  static string backwardsPrime(ll start, ll end);
};

bool is_prime(ll n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  int root = sqrt(n);
  for (int i = 3; i < root + 1; i += 2)
    if ((n % i) == 0) return false;
  return true;
}

string BackWardsPrime::backwardsPrime(ll start, ll end) {
  string ret;
  for (ll i = start; i <= end; ++i) {
    string i_str = to_string(i);
    reverse(i_str.begin(), i_str.end());
    ll i_reversed = stoll(i_str);
    if (i != i_reversed && is_prime(i) && is_prime(i_reversed))
      ret += to_string(i) + " ";
  }
  return ret.substr(0, ret.size() - 1);
}
int main()
{
	string r1 = BackWardsPrime::backwardsPrime(1095402, 1095404);

	return 0;
}

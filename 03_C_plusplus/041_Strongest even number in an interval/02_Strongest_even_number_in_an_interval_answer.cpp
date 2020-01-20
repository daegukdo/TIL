// c++ code-war
/*
issue description

Strongest even number in an interval

A strongness of an even number is the number of times we can successively divide by 2 until we reach an odd number starting with an even number n.

For example, if n = 12, then

12 / 2 = 6
6 / 2 = 3
So we divided successively 2 times and we reached 3, so the strongness of 12 is 2.

If n = 16 then

16 / 2 = 8
8 / 2 = 4
4 / 2 = 2
2 / 2 = 1
we divided successively 4 times and we reached 1, so the strongness of 16 is 4

Task :
Given a closed interval [n, m], return the even number that is the strongest in the interval. 

If multiple solutions exist return the smallest strongest even number.

Note that programs must run within the alloted server time; a naive solution will probably time out.

Constraints :
1 <= n < m <= INT_MAX

Examples :
[1, 2]    -->   2  # 1 has strongness 0, 2 has strongness 1
[5, 10]   -->   8  # 5, 7, 9 have strongness 0; 6, 10 have strongness 1; 8 has strongness 3
[48, 56]  -->  48
*/

#include<iostream>

using namespace std;

int strongest_even(int n, int m);

int main()
{
	int a1 = strongest_even(1, 2);      // Equals(2)          // 1        2
	int a2 = strongest_even(1, 3);      // Equals(2)          // 2        2
	int a3 = strongest_even(5, 10);     // Equals(8)          // 5        4
	int a4 = strongest_even(48, 56);    // Equals(48)         // 8        8
	int a5 = strongest_even(129, 193);  // Equals(192)        // 64       64
	int a6 = strongest_even(256, 512);  // Equals(512)        // 256      256
	int a7 = strongest_even(2, 1025);   // Equals(1024)       // 1023     512

	return 0;
}

int strongest_even(int n, int m) {
  if (n == m) return n;
  else {
    n = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
    m = (m % 2 == 0) ? m / 2 : (m - 1) / 2;
    return 2 * strongest_even(n, m);
  }
}
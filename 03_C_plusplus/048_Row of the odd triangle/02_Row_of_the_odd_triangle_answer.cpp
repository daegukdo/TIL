// c++ code-war
/*
issue description

Row of the odd triangle

Given a triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...
find the triangle's row knowing its index (the rows are 1-indexed), e.g.:

odd_row(1)  ==  [1]
odd_row(2)  ==  [3, 5]
odd_row(3)  ==  [7, 9, 11]
Note: your code should be optimized to handle big inputs.

The idea for this kata was taken from this kata: Sum of odd numbers
*/

#include <vector>

typedef unsigned long long ull;
typedef std::vector<ull> vull;

vull odd_row(ull row) {
  vull v(row);
  ull base = row * (row - 1);
  for (ull i = 0; i < row; i++) {
      v[i] = base + i * 2 + 1;
  }
  return v;
}
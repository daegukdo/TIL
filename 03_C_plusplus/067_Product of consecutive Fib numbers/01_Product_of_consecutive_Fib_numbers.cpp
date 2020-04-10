// c++ code-war
/*
@ issue description

Product of consecutive Fib numbers

@ Description

The Fibonacci numbers are the numbers in the following integer sequence (Fn):

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...

such as

F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

F(n) * F(n+1) = prod.

Your function productFib takes an integer (prod) and returns an array:

[F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)
depending on the language if F(n) * F(n+1) = prod.

If you don't find two consecutive F(m) verifying F(m) * F(m+1) = prodyou will return

[F(m), F(m+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)
F(m) being the smallest one such as F(m) * F(m+1) > prod.

Some Examples of Return:
(depend on the language)

productFib(714) # should return (21, 34, true), 
                # since F(8) = 21, F(9) = 34 and 714 = 21 * 34

productFib(800) # should return (34, 55, false), 
                # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55
-----
productFib(714) # should return [21, 34, true], 
productFib(800) # should return [34, 55, false], 
-----
productFib(714) # should return {21, 34, 1}, 
productFib(800) # should return {34, 55, 0},        
-----
productFib(714) # should return {21, 34, true}, 
productFib(800) # should return {34, 55, false}, 

Note:
You can see examples for your language in "Sample Tests".
*/

#include <vector>

using namespace std;

typedef unsigned long long ull;

class ProdFib
{
private:
	static ull fib(ull num);

public:
	static std::vector<ull> productFib(ull prod);
};

ull ProdFib::fib(ull num)
{
   if(num == 1)
      return 1;
   else if(num == 2)
      return 1;
   else
      return fib(num - 1) + fib(num - 2);
}

std::vector<ull> ProdFib::productFib(ull prod)
{
	ull fb1 = 0;
	ull fb2 = 0;

	ull count = 1;

	bool is2Fb = false;

	while(true)
	{
		fb1 = ProdFib::fib(count);
		fb2 = ProdFib::fib(count + 1);

		if(fb1 * fb2 == prod)
		{
			is2Fb = true;
			break;
		}

		if(fb1 * fb2 > prod)
		{
			break;
		}

		count++;
	}

	vector<ull> prodFibVect;

	prodFibVect.push_back(fb1);
	prodFibVect.push_back(fb2);
	prodFibVect.push_back(is2Fb);

	return prodFibVect;
}

int main()
{
	ProdFib::productFib(714);

	return 0;
}
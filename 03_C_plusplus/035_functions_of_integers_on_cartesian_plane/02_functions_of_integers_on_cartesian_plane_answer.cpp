// c++ code-war
/*
issue description

Functions of Integers on Cartesian Plane

Consider integer coordinates x, y in the Cartesian plan and three functions f, g, h defined by:

f: 1 <= x <= n, 1 <= y <= n --> f(x, y) = min(x, y)
g: 1 <= x <= n, 1 <= y <= n --> g(x, y) = max(x, y)
h: 1 <= x <= n, 1 <= y <= n --> h(x, y) = x + y
where n is a given integer (n >= 1, guaranteed) and x, y are integers.

In the table below you can see the value of the function f with n = 6.

---	0	1	2	3	4	5	6
6	-	1	2	3	4	5	6
5	-	1	2	3	4	5	5
4	-	1	2	3	4	4	4
3	-	1	2	3	3	3	3
2	-	1	2	2	2	2	2
1	-	1	1	1	1	1	1
0	-	-	-	-	-	-	-
The task is to calculate the sum of f(x, y), g(x, y) and h(x, y) for all integers x and y such that (1 <= x <= n, 1 <= y <= n).

The function sumin (sum of f) will take n as a parameter and return the sum of min(x, y) in the domain 1 <= x <= n, 1 <= y <= n. 

The function sumax (sum of g) will take n as a parameter and return the sum of max(x, y) in the same domain. 

The function sumsum (sum of h) will take n as a parameter and return the sum of x + y in the same domain.

#Examples:

sumin(6) --> 91
sumin(45) --> 31395
sumin(999) --> 332833500
sumin(5000) --> 41679167500

sumax(6) --> 161
sumax(45) --> 61755
sumax(999) --> 665167500
sumax(5000) --> 83345832500

sumsum(6) --> 252
sumsum(45) --> 93150
sumsum(999) --> 998001000
sumsum(5000) --> 125025000000
#Hint:

Try to avoid nested loops
Note that h = f + g
*/

using namespace std;

class Funij
{

  public:
  static unsigned long long sumin(unsigned long long n);
  static unsigned long long sumax(unsigned long long n);
  static unsigned long long sumsum(unsigned long long n);
};

unsigned long long Funij::sumin(unsigned long long n)
{
  return static_cast<unsigned long long>(n * (n + 1) * (2 * n + 1) / 6);
}

unsigned long long Funij::sumax(unsigned long long n)
{
  return static_cast<unsigned long long>(n * (n + 1) * (4 * n - 1) / 6);
}

unsigned long long Funij::sumsum(unsigned long long n)
{
  return static_cast<unsigned long long>(n * n * (n + 1));
}

int main()
{
	unsigned long long r01 = Funij::sumin(6);
	unsigned long long r02 = Funij::sumin(45);
	unsigned long long r03 = Funij::sumin(999);
	unsigned long long r04 = Funij::sumin(5000);

	unsigned long long r05 = Funij::sumax(6);
	unsigned long long r06 = Funij::sumax(45);
	unsigned long long r07 = Funij::sumax(999);
	unsigned long long r08 = Funij::sumax(5000);

	unsigned long long r09 = Funij::sumsum(6);
	unsigned long long r10 = Funij::sumsum(45);
	unsigned long long r11 = Funij::sumsum(999);
	unsigned long long r12 = Funij::sumsum(5000);

	return 0;
}
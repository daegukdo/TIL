// c++ code-war
/*
@ issue description

Common Denominators

@ Description

Common denominators

You will have a list of rationals in the form

 { {numer_1, denom_1} , ... {numer_n, denom_n} } 
or

 [ [numer_1, denom_1] , ... [numer_n, denom_n] ] 
or

 [ (numer_1, denom_1) , ... (numer_n, denom_n) ] 
where all numbers are positive ints.

You have to produce a result in the form

 (N_1, D) ... (N_n, D) 
or

 [ [N_1, D] ... [N_n, D] ] 
or

 [ (N_1', D) , ... (N_n, D) ] 
or

{{N_1, D} ... {N_n, D}} 
or

"(N_1, D) ... (N_n, D)"
depending on the language (See Example tests)

in which D is as small as possible and

 N_1/D == numer_1/denom_1 ... N_n/D == numer_n,/denom_n.

Example:

convertFracs [(1, 2), (1, 3), (1, 4)] `shouldBe` [(6, 12), (4, 12), (3, 12)]

Note:
Due to the fact that first translations were written long ago - more than 4 years - these translations have only irreducible fractions. 

Newer translations have some reducible fractions. 

To be on the safe side it is better to do a bit more work by simplifying fractions even if they don't have to be.

output is then "6 12 4 12 3 12"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fracts
{
private:
	static unsigned long long gcd(unsigned long long num1, unsigned long long num2);
	static unsigned long long lcm(unsigned long long num1, unsigned long long num2);

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};

unsigned long long Fracts::gcd(unsigned long long num1, unsigned long long num2)
{
	unsigned long long nb1 = 0;
	unsigned long long nb2 = 0;

	if(num1 > num2)
	{
		nb1 = num1;
		nb2 = num2;
	}
	else
	{
		nb2 = num1;
		nb1 = num2;
	}

	unsigned long long numdiv = 0;

	while (nb2 != 0)
	{
		numdiv = nb1 % nb2;
		nb1 = nb2;
		nb2 = numdiv;
	}
	return nb1;
}

unsigned long long Fracts::lcm(unsigned long long num1, unsigned long long num2)
{
	return num1 * num2 / gcd(num1, num2);
}

std::string Fracts::convertFrac(std::vector<std::vector<unsigned long long>> &lst)
{
	string output = "";
	int lstCapa = lst.capacity();
	int lstCapaIn = 0;

	vector<unsigned long long> babyVect;
	vector<unsigned long long> motherVect;

	for(int i = 0; i < lstCapa; i++)
	{
		lstCapaIn = lst[i].capacity();

		for(int j = 0; j < lstCapaIn; j++)
		{
			if(j % 2 == 0)
			{
				babyVect.push_back(lst[i][j]);
			}
			else
			{
				motherVect.push_back(lst[i][j]);
			}
		}
	}

	unsigned long long num1 = 0;
	unsigned long long num2 = 0;

	for(int i = 0; i < motherVect.size(); i++)
	{
		num2 = motherVect[i];

		if(num1 == 0)
		{
			num1 = num2;
		}
		else
		{
			num1 = lcm(num1, num2);
		}
	}

	unsigned long long lcmOfbabyVect = num1;

	unsigned long long mulNum = 0;

	for(int i = 0; i < motherVect.size(); i++)
	{
		mulNum = lcmOfbabyVect / motherVect[i];

		output += "(";
		output += std::to_string(babyVect[i] * mulNum);
		output += ",";
		output += std::to_string(lcmOfbabyVect);
		output += ")";
	}

	return output;
}


int main()
{
	unsigned long long n1[2] = {1, 2};
	unsigned long long n2[2] = {1, 3};
	unsigned long long n3[2] = {1, 4};

	vector<unsigned long long> v1(n1, n1 + sizeof n1 / sizeof n1[0]);
	vector<unsigned long long> v2(n2, n2 + sizeof n2 / sizeof n2[0]);
	vector<unsigned long long> v3(n3, n3 + sizeof n3 / sizeof n3[0]);

	vector<unsigned long long> vv1[3] = {v1, v2, v3};

	vector<vector<unsigned long long>> r1(vv1, vv1 + sizeof vv1 / sizeof vv1[0]);

	string results = Fracts::convertFrac(r1);

	return 0;
}
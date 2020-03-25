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
public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};

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

		for(int j = 0; i < lstCapaIn; i++)
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

	return "";
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
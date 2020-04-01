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

#include <string>
#include <vector>
#include <sstream>

#define SSTRING(x)(std::ostringstream() << std::dec << x ).str()
        
class Fracts
{

private:
    static unsigned long long gcd(unsigned long long a, unsigned long long b);

    static unsigned long long lcm(unsigned long long a, unsigned long long b);
public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst);
};

unsigned long long Fracts::gcd(unsigned long long a, unsigned long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

unsigned long long Fracts::lcm(unsigned long long a, unsigned long long b)
{
    return a * b / gcd(a, b);
}

std::string Fracts::convertFrac(std::vector<std::vector<unsigned long long>> &lst)
{
    unsigned long long lcmall = 1;
    for (auto item : lst)
    {
        lcmall = lcm(lcmall, item[1]);
    }
    std::string result = "";
    for (auto item : lst)
    {
        unsigned long long r = (lcmall / item[1]) * item[0];
        std::string num = SSTRING(r);
        std::string den = SSTRING(lcmall);
        result = result + "(" + num + "," + den + ")";
    }
    return result;
}
// c++ code-war
/*
issue description

Complementary DNA

Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the "instructions" for the development and functioning of living organisms.

If you want to know more http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". 

You have function with one side of the DNA (string, except for Haskell); you need to get the other complementary side. 

DNA strand is never empty or there is no DNA at all (again, except for Haskell).

More similar exercise are found here http://rosalind.info/problems/list-view/ (source)

DNA_strand ("ATTGC") # return "TAACG"

DNA_strand ("GTAT") # return "CATA"
*/

#include <string>

std::string DNAStrand(const std::string& dna);
char ComplementDNA(char partialDNA);

int main()
{
	std::string a = DNAStrand("ATTGC");
	std::string b = DNAStrand("GTAT");
	return 0;
}

std::string DNAStrand(const std::string& dna)
{
	std::string complementaryDNA = "";

	int dnaLength = dna.length();

	for(int i = 0; i < dnaLength; i++)
	{
		complementaryDNA = complementaryDNA + ComplementDNA(dna[i]);
	}

	return complementaryDNA;
}

char ComplementDNA(char partialDNA)
{
	if(partialDNA == 'A')
	{
		return 'T';
	}
	else if(partialDNA == 'T')
	{
		return 'A';
	}
	else if(partialDNA == 'C')
	{
		return 'G';
	}
	else if(partialDNA == 'G')
	{
		return 'C';
	}
}
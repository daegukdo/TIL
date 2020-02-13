// c++ code-war
/*
issue description

Sums of Parts

Let us consider this example (array written in general format):

ls = [0, 1, 3, 6, 10]

Its following parts:

ls = [0, 1, 3, 6, 10]
ls = [1, 3, 6, 10]
ls = [3, 6, 10]
ls = [6, 10]
ls = [10]
ls = []

The corresponding sums are (put together in a list): [20, 20, 19, 16, 10, 0]

The function parts_sums (or its variants in other languages) will take as parameter a list ls and return a list of the sums of its parts as defined above.

Other Examples:
ls = [1, 2, 3, 4, 5, 6] 
parts_sums(ls) -> [21, 20, 18, 15, 11, 6, 0]

ls = [744125, 935, 407, 454, 430, 90, 144, 6710213, 889, 810, 2579358]
parts_sums(ls) -> [10037855, 9293730, 9292795, 9292388, 9291934, 9291504, 9291414, 9291270, 2581057, 2580168, 2579358, 0]

Notes
Some lists can be long.
Please ask before translating: some translations are already written and published when/if the kata is approved.
*/

#include <vector>
#include <numeric>

using namespace std;

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls);

int main()
{
	unsigned long long arr1[] = {1, 2, 3, 4, 5, 6};
    vector<unsigned long long> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );

	vector<unsigned long long> result = partsSum(vec1);

	return 0;
}

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& xs) {
  std::vector<unsigned long long> res(xs.size() + 1);
  std::partial_sum(xs.crbegin(), xs.crend(), res.rbegin() + 1);
  return res;
}
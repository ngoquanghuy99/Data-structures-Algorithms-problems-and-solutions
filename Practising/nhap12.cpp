#include <bits/stdc++.h>
using namespace std;
int main(){
	
	std::size_t n = 5;
	std::size_t k = 3;
	
	std::vector<int> ints;
	for (int i = 0; i < n; ints.push_back(i++));
	
	do
	{
	   for (int i = 0; i < k; ++i)
	   {
	      std::cout << ints[i];
	   }
	   std::cout << "\n";
	}
	while(next_combination(ints.begin(),ints.begin() + k,ints.end()));
}

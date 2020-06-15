#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i,min=1000,counter,j;
	string s[n];
	for (i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n);
	do{
			counter=0;
			for (i=0;i<n-1;i++){
				for (j=0;j<s[i].length();j++)
					if(s[i+1].find(s[i][j])!=string::npos) counter++;
			}
		if(counter<min) min=counter;
	}
	while(next_permutation(s,s+n));
	cout<<min;
	return 0;
}

#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std; 

#define MAX_COUNT 1000000

vector<string> vec; 

void generateNumbersUtil() { 
	queue<string> q; 
	q.push("9"); 
	for (int count = MAX_COUNT; count > 0; count--){ 
		string s1 = q.front(); 
		q.pop(); 

		vec.push_back(s1); 
		string s2 = s1; 
		q.push(s1.append("0")); 
		q.push(s2.append("9")); 
	} 
} 

string findSmallestMultiple(int n){ 
	for (int i = 0; i < vec.size(); i++)  
		if (atoi(vec[i].c_str())%n == 0) 
			return vec[i];		 
} 
int main() { 
	ios_base::sync_with_stdio(false);
	generateNumbersUtil();	 
	int t = 0, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout << findSmallestMultiple(n) << endl;
	}
	return 0; 
} 


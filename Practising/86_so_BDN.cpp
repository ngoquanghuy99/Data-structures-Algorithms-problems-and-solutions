#include <bits/stdc++.h> 
using namespace std; 

bool isBinaryNum(int N) { 
	while (N > 0) { 
		int digit = N % 10; 
		if (digit != 0 && digit != 1) 
			return false; 
		N /= 10; 
	} 
	return true; 
} 

int mod(string t, int N) { 
	int r = 0; 
	for (int i = 0; i < t.length(); i++) { 
		r = r * 10 + (t[i] - '0'); 
		r %= N; 
	} 
	return r; 
} 

string getMinimumMultipleOfBinaryDigit(int N) { 
	queue<string> q; 
	set<int> visit; 
	string t = "1"; 
	q.push(t); 
	while (!q.empty()) { 
		t = q.front();	 q.pop();  
		int rem = mod(t, N); 
		if (rem == 0) 
			return t; 
		else if(visit.find(rem) == visit.end()){ 
			visit.insert(rem); 
			q.push(t + "0"); 
			q.push(t + "1"); 
		} 
	} 
} 

int main() { 
	int t = 0; cin >> t;
	while (t--){
		int N; cin >> N;
		cout << getMinimumMultipleOfBinaryDigit(N) << endl;
	}  
	return 0; 
} 


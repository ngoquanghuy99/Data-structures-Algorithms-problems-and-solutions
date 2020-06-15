#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector <long> solve(long a[], long n){
	vector<long> ans(n+1, -1);
	stack<long> s;
	s.push(n-1);
	long next;
	for(int i = n-2; i >= 0; i--){
		next = a[i];
		while(!s.empty() && next > a[s.top()]){
			ans[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	return ans;
}

int main(){
	long n;
	cin >> n;
	long a[100005];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<long> ans = solve(a, n);
	for(int i = 0; i < n; i++){
		if(ans[i] == -1){
			cout << i + 1 << " ";
		}
		else{
			cout << i - ans[i] << " ";
		}
	}
	return 0;
}

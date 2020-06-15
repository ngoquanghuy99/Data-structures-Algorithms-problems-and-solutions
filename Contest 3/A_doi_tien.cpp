/*
Author: Ngo Quang Huy
Problem: A - Doi tien using Greedy 
*/
#include<iostream>
#include<vector>
using namespace std;
int deno[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int s = sizeof(deno)/sizeof(deno[0]);
int n; 
void process(int n){
	int count = 0;
	vector <int> v;
	for(int i=s-1; i>=0; i--){
		while(deno[i] <= n){
			n-=deno[i];
			count ++;
		}
	}
	cout << count << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while(t--){
		cin >> n;
		process(n);
	}
	return 0;
}

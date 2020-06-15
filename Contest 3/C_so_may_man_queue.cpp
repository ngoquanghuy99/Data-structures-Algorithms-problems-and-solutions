#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdlib>
#include<cstring>
#define i64 long long
#define p push
#define MAX_COUNT 1000000
using namespace std;
vector <string> vec;
i64 summ(string x){
	i64 sum = 0;
	for(int i=0; i<x.size(); i++)
		sum += (x[i]-'0');
	return sum;
}
void generate(){
	queue <string> q;
	q.p("4");
	for(int count = MAX_COUNT; count > 0; count--){
		string s1 = q.front();
		q.pop();
		vec.push_back(s1);
		string s2 = s1;
		q.p(s1.append("4"));
		q.p(s2.append("7"));
	}
}
void lucky_number(int n){
	for(int i=0; i<vec.size(); i++)
		if(summ(vec[i]) == n){
			cout << vec[i] << endl;
			break;
		}	
	//	cout << vec[i] << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0, n;
	cin >> t;
	while(t--){
		cin >> n;
		generate();
		lucky_number(n);
	}
	return 0;
}

#include <iostream>
#include <map>
#include <queue>

using namespace std;
void trang(){
	string s; int k;
	map <char, int> hash;
	cin >> k;
	cin >> s;
	if(k > s.size()){
		cout << 0; 
		return;
	}
	for(int i = 0; i < s.size(); i++) hash[s[i]]++;
	priority_queue <int> Q;
		
	for(auto i : hash) Q.push(i.second);
	while (k--){
		int temp = Q.top(); Q.pop();
		temp--;
		Q.push(temp);
	}
	int sum = 0;
	while (!Q.empty()){
		int temp = Q.top(); Q.pop();
		sum += temp*temp;
	}
	cout << sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		trang();
		cout << endl;
	}
	return 0;
}

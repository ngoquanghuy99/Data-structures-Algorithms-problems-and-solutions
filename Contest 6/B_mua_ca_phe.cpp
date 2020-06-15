#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
const int Max = 100001;
int n, x[Max], q, y[Max], pos;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i];
	sort(x, x+n);
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> y[i];
		if(y[i] < x[0]) pos = 0;
		else pos = (upper_bound(x, x+n, y[i]) - x);
		v.push_back(pos);
	}
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << endl;
}

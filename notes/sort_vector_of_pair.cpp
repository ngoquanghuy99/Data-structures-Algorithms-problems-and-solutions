#include <iostream>
#include <vector>
#include <algorithm>
#define mp make_pair
using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
typedef vector <pii> vii;
typedef vector <ppi> vpi;
typedef vector <pip> vip;
bool sort_by_second(const pii &u, const pii &v){
	return u.second < v.second;
}
int main(){
	vii a;
	for(int i = 0; i < 10; i++){
		int x, y;
		cin >> x >> y;
		a.push_back(mp(x,y));
	}
	cout << "------------- Original vector ----------------" << endl;	
	for(int i = 0; i < a.size(); i++){
		cout << a[i].first << " " << a[i].second;
		cout << endl;
	}
	cout << "--------------After sorting by first -------------" << endl; 
	std::sort(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++){
		cout << a[i].first << " " << a[i].second;
		cout << endl;
	}
	cout << "--------------- After sorting by second------------" << endl;
	std::sort(a.begin(), a.end(), sort_by_second);
	for(int i = 0; i < a.size(); i++){
		cout << a[i].first << " " << a[i].second;
		cout << endl;
	}
}

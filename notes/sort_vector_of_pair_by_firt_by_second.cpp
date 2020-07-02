// sort by the second element of the first element aka sort by first.second

#include <iostream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
typedef vector <pii> vii;
typedef vector <ppi> vpi;
typedef vector <pip> vip;
///  this function to sort by first by second
bool sort_by_second_of_first(const ppi &u, const ppi &v){
	return u.fi.se < v.fi.se;
}

// this function to sort by second
bool sort_by_second(const ppi &u, const ppi &v){
	return u.se < v.se;
}
int main(){
	vpi a;
	for(int i = 0; i < 5; i++){
		int x, y, z;
		cin >> x >> y >> z;
		a.pb(mp(mp(x,y),z));
	}
	cout << "-------------- Before sorting --------------" << endl;
	for(int i = 0; i < a.size(); i++){
		cout << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se;
		cout << endl;
	}
	cout << "------------------- After sorting by first by first (No need to use function, its default) --------------" << endl;
	// just use basic sort
	std::sort(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++){
		cout << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se;
		cout << endl;
	}
	cout << "------------------ After sorting by first by second (we have to use an extra function to compare or just swap those two elements :) )-----" << endl;
	std::sort(a.begin(), a.end(), sort_by_second_of_first);
	for(int i = 0; i < a.size(); i++){
		cout << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se;
		cout << endl;
	}
	cout << "------------ After sorting by second -------------" << endl;
	std::sort(a.begin(), a.end(), sort_by_second);
	for(int i = 0; i < a.size(); i++){
		cout << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se;
		cout << endl;
	}
	return 0;
} 

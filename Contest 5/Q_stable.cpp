#include <iostream>
#include <algorithm>
using namespace std;
long long n, a[100005];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i]; stable_sort(a,a+n); for(int i = 0; i < n; i++) cout << a[i] << " ";	
}

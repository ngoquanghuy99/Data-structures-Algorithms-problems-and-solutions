#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <sstream>
#define i64 long long
const i64 mod = 1000000007;

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n+1];
	for(int i=0; i<n; i++)
		cin >> a[i];
	int count = 1;
	int max = a[0];
	for(int i=0; i<n; i++){
		if(a[i] > max){
			max = a[i];
			count ++;
		}
	}
	cout << count;
	return 0;
}



#include <iostream>
#include <algorithm>
#include <iomanip>
#define nmax 1000007
using namespace std;
int t;
int a[nmax];
float s1 = 0, s2 = 0;

int main(){
	cin >> t;
	while(t--){
		s1 = s2 = 0;
		int count = 0;
		int n, c, d;
		cin >> n >> c >> d;
		for(int i = 0 ; i < n ; ++i)
			cin >> a[i];
		sort(a, a+n);
		int k = min(c, d);
		int i = n-1;
		while(k--){
			s1 += a[i];
			if(i>0)
				i--;
			count++;
		}
		s1 = s1/count;
		k = max(c, d);
		count = 0;
		while(k--){
			s2 += a[i];
			if(i > 0)
				i--;
			count++;
		}
		s2 = s2/count;
		cout << setprecision(6) << fixed << (s1+s2)<< endl;
	}
	return 0;
}


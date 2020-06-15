#include<iostream>
#include<stack>
using namespace std;
long long a[100001], rs[100001];
int main(){
	int time;
	cin >> time;
	while(time--){
		int n;
		cin >> n;
		for(int i = 0 ; i < n ; i++) cin >> a[i];
		long long MAX = -1e9;
		for(int i = 0; i < n; i++){
			int x = i;
			int y = i;
			while(x >= 0 && a[x] >= a[i]) x--;
			x++;
			while(y < n && a[y] >= a[i]) y++;
			y--;
			long long temp = a[i]*(y - x + 1);
			MAX = max(MAX, temp);
		}
		cout << MAX << endl;
	}
}

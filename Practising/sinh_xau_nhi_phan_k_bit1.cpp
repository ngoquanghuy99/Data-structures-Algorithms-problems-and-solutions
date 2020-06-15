// sinh xau nhi phan co k bit 1
#include <iostream>
using namespace std;
int n, a[110], k;

void init(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) a[i] = 0;
}
void printout(){
	for(int i = 1; i <= n; i++) cout << a[i];
	cout << endl;
}

bool isFinal(){
	for(int i = 1; i <= n; i++)
		if(a[i] != 1) return false;
	return true;
}
bool check(){
	int sum_k = 0;
	for(int i = 1; i <= n; i++)
		sum_k += a[i];
	if(sum_k == k) return true;
	return false;
}
void nextGen(){
	int i = n;
	while (a[i] == 1){
		a[i] = 0;
		i--;
	}
	a[i] = 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 0; cin >> T;
	while (T--){
		init();
		while (!isFinal()){
			if(check())
				printout();
			nextGen();
		}
	}
	return 0;
}

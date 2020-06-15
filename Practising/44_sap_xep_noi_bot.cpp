#include <bits/stdc++.h>

using namespace std;
int a[105], n;
void printout(){
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for(int i = 0; i < n; i++) cin >> a[i];
	int dem = 0, Trang = 0;
	
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				Trang = 1;
			}
		}
		if(Trang == 1){
			cout << "Buoc " << ++dem << ": ";
			printout();
		}
		Trang = 0;
	}
	return 0;
}

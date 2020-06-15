// 44 sap xep noi bot
#include <iostream>
using namespace std;

int main(){
	int n; cin >> n; int a[n+1];
	for(int i = 0; i < n; i++) cin >> a[i];
	int mrk = 0, stt = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				mrk = 1;
			}
		}
		if(mrk == 1){
			cout << "Buoc " << ++stt << ": ";
			for(int i = 0; i < n; i++) cout << a[i] << " ";
			cout << endl;
		}
		mrk = 0;
	}
}

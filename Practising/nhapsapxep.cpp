// tong hop sap xep
#include <iostream>
using namespace std;

int main(){
	int n; cin >> n; int a[n+1]; 
	for(int i = 0; i < n; i++) cin >> a[i];
	// sap xep doi cho truc tiep
//	for(int i = 0; i < n-1; i++){
//		for(int j = i+1; j < n; j++){
//			if(a[i] > a[j]) swap(a[i], a[j]);
//		}
//		cout << "Buoc " << i+1 << ": ";
//		for(int i = 0; i < n; i++) cout << a[i] << " ";
//		cout << endl;


// sap xep chon
//	for(int i = 0; i < n-1; i++){
//		int minval = a[i], minind = i;
//		for(int j = i+1; j < n; j++){
//			if(a[j] < minval){
//				minval = a[j];
//				minind = j;
//			}
//		}	
//		swap(a[i], a[minind]);
//		cout << "Buoc " << i+1 << ": ";
//		for(int i = 0; i < n; i++) cout << a[i] << " ";
//		cout << endl;
//	}



// sap xep chen
//	cout << "Buoc 0: " << a[0] << endl;
//	for(int i = 1; i < n; i++){
//		int j = i;
//		while (j > 0 && a[j-1] > a[j]){
//			swap(a[j-1], a[j]);
//			j--;
//		}
//		cout << "Buoc " << i << ": ";
//		for(int t = 0; t <= i; t++) cout << a[t] << " ";
//		cout << endl;
//	}


// sap xep noi bot
	int stt = 0, mrk = 0;
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
	// sap xep
}

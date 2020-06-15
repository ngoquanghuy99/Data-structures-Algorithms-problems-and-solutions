// sx chon
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n = 0; cin >> n;
	int a[n+1]; for(int i = 0; i < n; i++) cin >> a[i];
	int dem = 0;
	for(int i = 0; i < n-1; i++){
		int minindex = i;
		int minvalue = a[i];
		for(int j = i+1; j < n; j++){
			if(a[j] < minvalue){
				minvalue = a[j];
				minindex = j;
			}
		}
		swap(a[i], a[minindex]);
		cout << "Buoc " << i+1 << ": ";
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
}

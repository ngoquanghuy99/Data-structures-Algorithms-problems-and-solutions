/************************************************\

	you know that i can't stop thinkin bout you
	you're the source of everything i do

\************************************************/
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; int a[n+1];
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << "Buoc " << 0 << ": " << a[0] << endl;
	for(int i = 1; i < n; i++){
		int j = i;
		while (j > 0 && a[j-1] > a[j]){
			swap(a[j-1], a[j]);
			j--;
		}
		cout << "Buoc " << i << ": ";
		for(int t = 0; t <= i; t++) cout << a[t] << " ";
		cout << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int dem = 0;
void display(int a[], int n){
	cout << "Buoc " << ++dem <<": ";
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void selection_sort(int a[], int n){
	int i, j, minIndex, minValue;
	for(int i = 0; i < n - 1; i++){
		minIndex = i;
		minValue = a[i];
		for(int j = i + 1; j < n; j++)
			if(a[j] < minValue){
				minIndex = j;
				minValue = a[j];
			}	
		swap(a[i],a[minIndex]);
		display(a,n);
	}
}
int main(){
	int n, a[101];
	cin >> n;
	for(int i = 0; i < n; i++)	cin >> a[i];
	selection_sort(a,n);
	return 0;
}

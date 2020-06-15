#include<iostream>
using namespace std;
int x[100], A[200], xuoi[100], nguoc[100], n;
int dem = 0;
bool init(){
	cin>>n;
	for(int i=1; i<=n; i++)
		A[i] = true;
	for(int i=1; i<=2*n-1; i++)
		xuoi[i] = true;
	for(int i=1; i<=2*n-1; i++)
		nguoc[i] = true;
}
void back_track(int i){
	
	for(int j=1; j<=n; j++){
		if(A[j] && xuoi[i-j+n] && nguoc[i+j-1]){
			A[j] = xuoi[i-j+n] =nguoc[i+j-1] = false;
			x[i] = j;
			if(i==n) dem++;
			else back_track(i+1);
			A[j] = xuoi[i-j+n] =nguoc[i+j-1] = true;
		}
	}
}
int main(){
	init();
	back_track(1);
	cout<<dem;
	return 0;
}

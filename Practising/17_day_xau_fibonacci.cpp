#include<iostream>

using namespace std;
long long F[100];
void fibo(){
	F[0] = 0;
	F[1] = 1;
	for(int i=2; i<=92; i++)
		F[i] = F[i-1] + F[i-2];
}
char Fiboword(int n, long long i){
	if(n==1) return 'A';
	if(n==2) return 'B';
	if(i <= F[n-2]) return Fiboword(n-2,i);
	return Fiboword(n-1, i-F[n-2]);
}
int main(){
	int t = 0;
	cin>>t;
	long long n, i;
	fibo();
	while(t--){
		cin>>n>>i;
		cout<<Fiboword(n,i)<<endl;
	}
}

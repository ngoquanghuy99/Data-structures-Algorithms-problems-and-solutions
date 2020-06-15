#include<bits/stdc++.h>
using namespace std;
int n,k,s,sc;
int x[10];
bool check(){
	int tong=0;
	for(int i=1;i<=k;i++)
		tong += x[i];
	if(tong==s) return true;
	else return false;
}
void capnhat(){
	if(check()) sc++;
}
void in(){
	cout<<sc<<endl;
}
void Try(int i){
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if(i==k) capnhat();
		else Try(i+1);
	}
}
main(){
	while(1){
		cin>>n>>k>>s;
		if(n==0 && k==0 && s==0) {
			break;
		}
		sc=0;
		Try(1);
		in();
	}
}

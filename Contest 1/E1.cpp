#include<iostream>
using namespace std;

int n, k, soluong=0, tong=0, a[10][10], b[10];

int Next(){
	int i=n-1;
	while(i>0){
		if(b[i] < b[i+1]) break;
		i--;
	}
	if(i==0)
		return 0;
	for(int j=n; j>i; j--){
	    if(b[i] < b[j]){
		    swap(b[i], b[j]);
		    break;
		}
	}
	int temp=n;
	for(int j=i+1; j<temp; j++){
		swap(b[j], b[temp]);
		temp--;
	}
	return 1;
}

void Dem(){
	for(int i=1; i<=n; i++)
	    b[i]=i; 
	do{
	    for(int i=1; i<=n; i++){
		    tong+=a[b[i]][i];
	    }
	    if(tong == k){
		    for(int i=1; i<=n; i++)
		        cout<<b[i]<<" ";
		    cout<<endl;    
	    }
	    tong=0;
    }while(Next());
}
void Soluong(){
	for(int i=1; i<=n; i++)
	    b[i]=i; 
	do{
	    for(int i=1; i<=n; i++){
		    tong+=a[b[i]][i];
	    }
	    if(tong == k){
		    soluong++;   
	    }
	    tong=0;
    }while(Next());
    cout<<soluong<<endl;
}
main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
		    cin>>a[i][j];
	}
	Soluong();
	Dem();
}

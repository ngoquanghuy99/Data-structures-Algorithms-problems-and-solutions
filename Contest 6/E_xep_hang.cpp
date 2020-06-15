#include<iostream>

using namespace std;
int N, K;

int partition(int l, int r, int a[], int B[]){
	int x = a[l], i = l+1, j = r;
	do{
		while(i<=j&&a[i]<=x) i++;
		while(i<=j&&a[j]>x)	j--;
		if(i<j){
			swap(a[i],a[j]);
			swap(B[i],B[j]);
			i++; j--;
		}
	}while(i<=j);
	swap(a[l],a[j]);
	swap(B[l],B[j]);
	return j;
}

void qsort(int a[], int l, int r, int B[]){
	int k;
	if(l<r){
		k = partition(l,r,a,B);
		qsort(a,l,k-1,B);
		qsort(a,k+1,r,B);
	}
}

main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>N;
	int T[N+1], D[N+1];
	for(int i = 1;i<=N;i++) cin>>T[i]>>D[i];
	qsort(T,1,N,D);
	int kq  = T[1]+D[1];
	for(int i = 2;i<=N;i++){
		if(kq < T[i]) kq = T[i]+D[i];
		else kq +=D[i];
	}
	cout<<kq<<endl;
}

#include<iostream>
using namespace std;
int count;
void input(int A[], int B[], int K){
	for(int i=1; i<=K; i++){
		cin>>A[i];
		B[i] = A[i];
	}
}
bool isFinal(int A[], int N, int K){
	for(int i=1; i<=K; i++)
		if(A[i] != N-K+i) return false;
	return true;
}
void next_gen(int A[], int N, int K){
	if(isFinal(A,N,K)){
		count = K;
		cout<<count<<endl;
		
	}
	else{
		int i = K;
		while(A[i] == N-K+i)
		i--;
		A[i]++;
		for(int j=i+1; j<=K; j++)
			A[j] = A[i] + j - i;
	}
}

void check(int A[], int B[], int K){
	int k, count = 0;
	for(int i=1; i<=K; i++){
		k = 0;
		for(int j=1; j<=K; j++){
			if(B[i]==A[j]){
				k = 1;
				break;
			}
		}
		if(!k)
			count++;
	}
	if(count!=0) cout<<count<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int T, N, K = 0;
	int A[41], B[41];
	cin>>T;
	while(T--){
		cin>>N>>K;
		input(A,B,K);
		next_gen(A,N,K);
		check(A,B,K);
	}
	return 0;
}

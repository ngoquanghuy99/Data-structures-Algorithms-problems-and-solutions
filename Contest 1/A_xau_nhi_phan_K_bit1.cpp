#include<iostream>
using namespace std;

void display(int B[], int N){
	for(int i=1; i<=N; i++)
		cout<<B[i];
	cout<<endl;
}
bool isFinal(int B[], int N){
	for(int i=1; i<=N; i++)
		if(B[i] != 1) return false;
	return true;
}

void Next_gen(int B[], int N){
	int i = N;
	while(B[i]==1){
		B[i] = 0;
		i--;
	}
	B[i] = 1;
}

bool check(int B[], int N, int K){
	int sum = 0;
	for(int i=1; i<=N; i++)
		sum += B[i];
	if(sum==K) return true;
	else return false;
}
void Generatives(int B[], int N, int K){
	while(!isFinal(B,N)){
		if(check(B,N,K))
			display(B,N);
		Next_gen(B,N);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int T, N, K = 0;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int B[17] = {0};
		Generatives(B,N,K);
	}
	return 0;
}

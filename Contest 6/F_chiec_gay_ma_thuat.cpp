#include<iostream>
#include<algorithm>
using namespace std;
int N, A[101], B[101];
void input(int A[], int N){
	for(int i=0; i<N; i++)
		cin>>A[i];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>N;
	int count = 0;
	input(A,N);
	input(B,N);
	sort(A, A+N);
	sort(B, B+N);
	for(int i=0; i<N; i++)
		if(A[i] <= B[i])
			count++;
	if(count == N)
		cout<<"YES";
	else cout<<"NO";
}

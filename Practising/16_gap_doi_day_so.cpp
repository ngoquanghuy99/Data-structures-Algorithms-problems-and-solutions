#include<iostream>
using namespace std;
long long S[60];
void init(){
	S[1] = 1;
	for(int i = 2; i <= 60; i++ ) 
		S[i] = 2*S[i-1] + 1;
}

int main(){
	int t;
	cin>>t;
	long long n, k;
	init();
	while(t--){
		cin>>n>>k;
		long long step = n - 1;
		while(k-1 != S[step]){
			if(k > S[step]) 
				k = k-S[step]-1;
			n--;
			step--;
			if( k == 1) {
				n = 1;
				break;
			}
		}
		cout<<n<<endl;
	}
}

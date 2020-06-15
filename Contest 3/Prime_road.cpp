#include<iostream>
#include<vector>
#include<memset>
#include<queue>

using namespace std;

int main(){
	vector <int> v;
	int s, t;
	cin >> s >> t;
	bool sieve[10000];
	memset(sieve, true, sizeof(sieve));
	for(int i=2; i*i<=9999; i++){
		if(sieve[i]){
			for(int j=i*i; j<=9999; j+=i)
				sieve[j] = false;
		}
	}
	for(int i=1000; i<=9999; j++)
		if(sieve[i])
			v.push_back(i);
	
}

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int T = 0, stt;
	cin>>T;
	string s;
	while(T--){
		cin>>stt;
		cin>>s;
		cout<<stt<<" ";
		if(next_permutation(s.begin(), s.end()))
			cout<<s<<endl;
		else	cout<<"BIGGEST"<<endl;
	}
	return 0;
}

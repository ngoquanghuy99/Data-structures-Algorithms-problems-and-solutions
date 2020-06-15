#include<iostream>
#include<stack>
using namespace std;
void conversion(string a, string b, int K){
	int la = a.length() - 1;
	int lb = b.length() - 1;
	int x, y;
	stack <int> s;
	int mem = 0;
	while(!(la < 0 && lb < 0)){
		x = (la >= 0)? a[la] - 48:0;
		y = (lb >= 0)? b[lb] - 48:0;
		long long temp = x + y + mem;
		mem = 0;
		if(temp >= K){
			mem = temp/K;
			temp -= K;
		}
		s.push(temp);
		la--;
		lb--;
	}
	if(mem != 0) s.push(mem);
	long long ans = 0;
	while(!s.empty()){
		int temp = s.top(); s.pop();
		ans = ans*10 + temp;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string a, b;
	int K;
	cin>>K>>a>>b;
	conversion(a, b, K);
}

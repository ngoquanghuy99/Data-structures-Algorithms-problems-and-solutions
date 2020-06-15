#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>

using namespace std;
void conv56(string &a){
	for(int i=0; i<a.size(); i++)
		if(a[i] == '5') a[i] = '6';
}
void conv65(string &a){
	for(int i=0; i<a.size(); i++)
		if(a[i] == '6') a[i] = '5';
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a, b, a1, b1;
	cin >> a >> b;
	a1 = a; b1 = b;
	
	conv65(a1); conv65(b1);
	
	int Min = atoi(a1.c_str()) + atoi(b1.c_str());

	conv56(a); conv56(b);
	
	int Max = atoi(a.c_str()) + atoi(b.c_str());
	
	cout << Min << " " << Max;
	return 0;
}


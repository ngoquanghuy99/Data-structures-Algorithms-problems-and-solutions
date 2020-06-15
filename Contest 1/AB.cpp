#include<iostream>
#include<vector>
using namespace std;
int n, k, OK, dem = 0;
string s;
vector <string> v;
void sinh(){
	int i = n-1;
	while(s[i] == 'B'){
		s[i] = 'A';
		i--;
	}
	if(i==-1) OK = 1;
	else s[i] = 'B';
}
bool check(){
	int count, countA = 0;
	for(int i=0; i<n; i++){
		count = 0;
		if(s[i] == 'A'){
			for(int j=i; j<i+k; j++)
				if(s[j] == 'A')
					count++;
			if(count==k)
				countA++;
		}
	}
	if(countA==1) return true;
	return false;
}
int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++)
		s += 'A';
	while(!OK){
		if(check()){
			dem++;
			v.push_back(s);
		}
		sinh();
	}
	cout<<dem<<endl;
	for(int i=0; i<v.size(); i++)
		cout<<v.at(i)<<endl;
}

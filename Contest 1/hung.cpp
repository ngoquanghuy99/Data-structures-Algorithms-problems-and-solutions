#include<iostream>
#include<string>

using namespace std;
string s;
int arr[10001];
int OK = 0;
int dem = 0;

bool isFinal(){
	for(int i=1; i<dem; i++)
		if(arr[i] < arr[i+1]) return false;
	return true;
}
void display(){
	for(int i=1; i<dem; i++)
		cout<<arr[i];
	cout<<endl;
}
void sinh(){
	int x = dem - 1;
	while(arr[x] > arr[x+1])	
		x--;
	if(x > 0){
		int k = dem;
		while(arr[x] > arr[k])
			k--;
		swap(arr[x], arr[k]);
		int r = dem, l = x+1;
		while(r < l){
			 swap(arr[r], arr[x]);
			 r--; l++;
		}
	}
	else
		OK = 1;	
}
void check(){
	if(!isFinal()){
		sinh();
		display();
		OK = 0;
	}
	else cout<<"BIGGEST"<<endl;
}
void str_to_num(){
	dem = 1;
	for(int i=0; i<s.size(); i++)
		arr[dem++] = s[i] - 48;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t = 0, stt;
	cin>>t;
	while(t--){
		cin>>stt;
		cin>>s;
		cout<<stt<<" ";
		str_to_num();
		check();
	}
}

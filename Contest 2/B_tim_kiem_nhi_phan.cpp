/*
Author: Ngo Quang Huy
Problem: B (binary_search)
*/

#include<iostream>
#include<algorithm>

using namespace std;
int const Max = 1000001;
int t = 0, n, k, arr[Max];
int binary_search(int arr[], int k, int left, int right){
	if(right >= left){
		int mid = left + (right - left) / 2;
		if(arr[mid] == k) return mid;
		if(arr[mid] > k) return binary_search(arr,k,left,mid-1);
		return binary_search(arr,k,mid+1,right);
	}
	return -1;
}
void input(int arr[], int n){
	for(int i=0; i<n; i++)
		cin>>arr[i];
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		input(arr,n);
		sort(arr,arr+n);
		int x = binary_search(arr,k, 0, n-1);
		x!=-1 ? cout<<x+1<<endl : cout<<"NO"<<endl;
	}
}

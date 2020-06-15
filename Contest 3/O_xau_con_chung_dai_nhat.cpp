/*

Author: Ngo Quang Huy
Problem: Xau con chung dai nhat

*/
#include<bits/stdc++.h>
// sua <= len thanh < len
using namespace std;
int a[1001][1001],i,j;
int main(){
	string s1,s2;
	cin >> s1 >> s2;
	int len1, len2;
	len1=s1.length();
	len2=s2.length();
	// co so quy hoach dong
	for(i=0; i<len1; i++){ // hang 
		a[i][0]=0;
	}
	for(i=0; i<len2; i++){ // cot
		a[0][i]=0;
	}
	
	for(i=0; i<len1; i++){
		for(j=0; j<len2; j++){
			if(s1[i]==s2[j]){
				a[i+1][j+1] = a[i][j]+1;
			}
			else{
				a[i+1][j+1] = max(a[i+1][j], a[i][j+1]);
			}
		}
	}
	cout << a[len1][len2];
	return 0;
}

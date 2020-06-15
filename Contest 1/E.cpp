#include<iostream>
using namespace std;
int n, matrix[10][10], c[10] = {0}, sum = 0, dem = 0, k, temp[10];
typedef struct list{
	int number[10];
}list;

list LIST[1000];

void Try(int i){
	for(int j = 0; j < n; j++){
		if(c[j] == 0){
			c[j] = 1;
			temp[i] = j;
			if(i == n - 1){
				for(int y = 0; y < n; y++) sum += matrix[y][temp[y]];
				if(sum == k){
					for(int z = 0; z < n; z++) LIST[dem].number[z] = temp[z] + 1;
					dem++;
					sum = 0;
				}else sum = 0;
				
			}else Try(i + 1);
			c[j] = 0;
		}
	}
}
int main(){	
	cin>>n>>k;
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			cin>>matrix[i][j];
	Try(0);
	cout<<dem<<endl;
	for(int i = 0; i < dem; i++){
		for(int j = 0; j < n; j++) cout<<LIST[i].number[j]<<" ";
		cout<<endl;
	}
}

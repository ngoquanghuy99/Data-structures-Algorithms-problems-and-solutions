#include<iostream>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
struct matrix{
	int hso[2][3];
};

int check(matrix a, matrix b){
	if(a.hso[0][0] != b.hso[0][0]) return 0;
	if(a.hso[0][1] != b.hso[0][1]) return 0;
	if(a.hso[0][2] != b.hso[0][2]) return 0;
	if(a.hso[1][0] != b.hso[1][0]) return 0;
	if(a.hso[1][1] != b.hso[1][1]) return 0;
	if(a.hso[1][2] != b.hso[1][2]) return 0;
	return 1;
}

void step(matrix s, matrix t){
	int dem = 0;
	if(check(s, t)){
		cout<<dem<<endl;
		return;
	}
	queue<matrix> q;
	q.push(s);
	int mark = 0;
	while(!q.empty()){
		
		
		dem++;
		for(int i = 1; i <= pow(2, mark); i++){
			matrix m1, m2;
			matrix top = q.front();q.pop();
			m1.hso[0][0] = top.hso[1][0];
			m1.hso[0][1] = top.hso[0][0];
			m1.hso[0][2] = top.hso[0][2];
			m1.hso[1][0] = top.hso[1][1];
			m1.hso[1][1] = top.hso[0][1];
			m1.hso[1][2] = top.hso[1][2];
			
			m2.hso[0][0] = top.hso[0][0];
			m2.hso[0][1] = top.hso[1][1];
			m2.hso[0][2] = top.hso[0][1];
			m2.hso[1][0] = top.hso[1][0];
			m2.hso[1][1] = top.hso[1][2];
			m2.hso[1][2] = top.hso[0][2];
			
			q.push(m1);
			q.push(m2);
		
			if(check(m1, t) || check(m2, t)){
				cout<<dem<<endl;
				return;
			}
				
			
		}
		mark++;
	}
}
int main(){
	matrix s, t;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++) cin>>s.hso[i][j];
		
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++) cin>>t.hso[i][j];
		
	step(s, t);	
}

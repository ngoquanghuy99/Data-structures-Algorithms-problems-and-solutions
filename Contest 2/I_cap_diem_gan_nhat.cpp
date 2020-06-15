#include<iostream>
using namespace std;
long long a[10] = {0},b[10],c[10], A, B, C, D, E, check = 0, chuaxet[10] = {0};
bool magic(){
	long long rs = 0;
	if(a[0] == 0) rs = A + B;
	else if(a[0] == 1) rs = A - B;
	else if(a[0] == 2) rs = A*B;
	
	if(a[1] == 0) rs = rs + C;
	else if(a[1] == 1) rs = rs - C;
	else if(a[1] == 2) rs = rs*C;
	
	if(a[2] == 0) rs = rs + D;
	else if(a[2] == 1) rs = rs - D;
	else if(a[2] == 2) rs = rs*D;
	
	if(a[3] == 0) rs = rs + E;
	else if(a[3] == 1) rs = rs - E;
	else if(a[3] == 2) rs = rs*E;
	
	if(rs == 23) return 1;
	return 0;
}

void Try2(int i){
	for(int j = 0; j < 5; j++){
		if(chuaxet[j] == 0){
			c[i] = j;
			chuaxet[j] = 1;
			if(i == 4){
				A = b[c[0]];
				B = b[c[1]];
				C = b[c[2]];
				D = b[c[3]];
				E = b[c[4]];
				if(magic()){
					check = 1;
					return;
				}
			}else Try2(i + 1);
			chuaxet[j] = 0;
		}
	}
}
void Try(int i){
	for(int j = 0; j < 3; j++){
		a[i] = j;
		if(i == 3){
			Try2(0);
			if(check) return;
		}else Try(i + 1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		check = 0;
		for(int i = 0; i < 5; i++) cin>>b[i];
		for(int i = 0; i < 5; i++) chuaxet[i] = 0;
		Try(0);
		if(check == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

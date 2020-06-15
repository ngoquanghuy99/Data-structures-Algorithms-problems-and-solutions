#include<iostream>
using namespace std;

long long xl(){
    char x[155];
    cin.getline(x,150);
    if(*x==0) return 1;
    long long k=1;
    int m=0,d=0;
    for(char *p = x; *p ; p++){
        if(*p == '['){
			d++;
			if(m < d){
				k *= 2; m = d;
			}
		}
        else d--;
    }
    return k;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
        cin.ignore();
    long long *A=new long long [t+5];
    for(int i = 1; i <= t; i++) A[i] = xl();
    for(int i = 1; i <= t; i++) cout << i << " " << A[i] << endl;
    return 0;
}


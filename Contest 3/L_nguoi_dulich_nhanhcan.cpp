#include<iostream>
using namespace std;
int x[100], xopt[100], fopt, n, c[100][100], cmin, unused[100], sum;

void input(){
//	cout<<"Nhap so thanh pho: ";
	cin>>n;
//	cout<<"Nhap ma tran chi phi: "<<endl;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>c[i][j];
	for(int i=1; i<=n; i++)
		unused[i] = true;
}
void swap(){
	for(int i=1; i<=n; i++)
		xopt[i] = x[i];
}
void update(){
	int sum1 = 0;
	sum1 = sum + c[x[n]][x[1]];
	if(sum1 < fopt){
		swap();
		fopt = sum1;
	}
}
int find_cmin(){
	int minimum = 10000;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(c[i][j] < minimum)
				minimum = c[i][j];
	return minimum;
}
void Try(int i){
	for(int j=2; j<=n; j++){
		if(unused[j]){
			x[i] = j;
			unused[j] = false;
			sum += c[x[i-1]][x[i]];
			if(i==n)
				update();
			else if(sum + (n-i+1)*cmin < fopt)
				Try(i+1);
			sum -= c[x[i-1]][x[i]];
			unused[j] = true;
		}
	}
}
void printRes(){
////	cout<<"Hanh trinh toi uu nhat la: ";
//	for(int i=1; i<=n; i++)
//		cout<<xopt[i]<<"-->";
//	cout<<1<<endl;
//	cout<<"Chi phi hanh trinh nay la: ";
	cout<<fopt;
}
int main(){
	input();
	sum = 0;
	x[1] = 1;
	fopt = 10000;
	cmin = find_cmin();
	Try(2);
	printRes();
}

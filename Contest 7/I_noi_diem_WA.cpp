#include <iostream>
#include <cmath>
using namespace std;

double dau[101],cuoi[101];
double c[100000];
int u[100001],v[100001];
int N,M,f[101];

double kc(int i,int j){
	return (double)sqrt((dau[i]-dau[j])*(dau[i]-dau[j])+(cuoi[i]-cuoi[j])*(cuoi[i]-cuoi[j]));
}

void Sort(int F,int L){
	int j=F,k;
	while(j<=L/2){
		if(2*j<L&&c[2*j+1]<c[2*j]) k=2*j+1;
		else  k=2*j;
		if(c[k]<c[j]){
			int t1=u[j],t2=v[j];
			double t3=c[j];
			u[j]=u[k];v[j]=v[k];c[j]=c[k];
			u[k]=t1,v[k]=t2,c[k]=t3;j=k;
		}
		else j=L;
	}
}

int Ktra(int i){
	int tro=i;
	while(f[tro]>0) tro=f[tro];
	return tro;
//	if(f[i] != i) f[i] = Ktra(f[i]);
//	return f[i];
}

void Union(int i,int j){
	int x = f[i] + f[j];
	if(f[i] > f[j]){
		f[i] = j;
		f[j] = x;
	}
	else{
		f[j] = i;
		f[i] = x;
	}
}

void Krusal(){
	for(int i = 1; i <= N; i++) f[i]=-1;
	for(int i = M / 2; i > 0; i--) Sort(i,M);
	long long last = M, cq = 0, dq = 0;
	double min1 = 0;
	while(dq < N-1 && cq < M){
		cq++;
		int u1 = u[1], v1 = v[1];
		int r1 = Ktra(u1), r2 = Ktra(v1);
		if(r1 != r2){
			dq++; Union(r1,r2);
			min1 = min1 + c[1];
		}
		u[1] = u[last]; v[1] = v[last]; c[1] = c[last]; last--;
		Sort(1,last);
	}
	printf("%.6lf\n",min1);
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 0; cin >> T;
	while(T--){
		cin >> N ;
		for(int i = 1; i <= N; i++) cin >> dau[i] >> cuoi[i];
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i < j){
				M++;
				c[M] = kc(i,j);
				u[M] = i;
				v[M] = j;
				}
			}
		}		
		Krusal();
	}
}



#include<iostream>
#include<algorithm>
#define FOR(i,n) for(int i=0; i<n; i++)
using namespace std;
const int Max = 100001;
int n;
bool check[Max];
struct CV{
	int dau;
	int cuoi;
};

bool CVcompare(CV cv1, CV cv2){
	return cv1.cuoi < cv2.cuoi;
}
void process(CV cv[]){
	FOR(i,n){
		cin >> cv[i].dau >> cv[i].cuoi;
		check[i] = false;
	}
		sort(cv, cv+n, CVcompare);
		int i = 0; check[i] = true;
		int dem = 1;
		for(int j=1; j<n; j++){
			if(cv[i].cuoi <= cv[j].dau){
				dem ++;
				i = j;
				check[i] = true;
			}
		}
		cout << dem << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while(t--){
		cin >> n;
		CV cv[n];
		process(cv);
	}
	return 0;
}

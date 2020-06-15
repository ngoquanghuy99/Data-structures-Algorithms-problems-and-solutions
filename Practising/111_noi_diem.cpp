#include <iostream>
#include<algorithm>
#include <vector>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;
struct data{
    int st, en;
    double cost;
    data(){};
    data(int s, int e, double c){st = s; en = e; cost = c;}
    friend bool operator < (data A, data B){
        return A.cost < B.cost;
    }
};
int n, m;
double u, v;
vector <data> E;
int parent[200005];

int findset(int i) {
    if(parent[i] < 0) return i;
    parent[i] = findset(parent[i]);
    return parent[i];
}

void MST(){
    double d = 0;
    memset(parent,-1,sizeof(parent));
    sort(E.begin(), E.end());
    for(int i=0;i< E.size();i++){
        int u = findset(E[i].st);
        int v = findset(E[i].en);
        if(u != v){
            parent[u] = v;
            d += E[i].cost;
        }
    }
    cout<<fixed<<setprecision(6)<<d<<endl;
}
main(){
	ios::sync_with_stdio(false);
	cin.tie();
	vector < pair<double, double> > point;
    int t;cin>>t;
    while(t--){
    	E.clear();
    	point.clear();
        cin >> n;
        for(int i=1;i<= n;i++){
            cin >> u >> v;
            point.push_back(make_pair(u, v));
        }
        for(int i = 0; i < n - 1; i++){
        	double x1, y1, x2, y2;
        	x1 = point[i].first;
        	y1 = point[i].second;
        	
        	data temp;
        	temp.st = i;
        	for(int j = i + 1; j < n; j++){
        		temp.en = j;
        		
        		x2 = point[j].first;
        		y2 = point[j].second;
//        		cout<<x1<<" "<<y1<<" : "<<x2<<" "<<y2<<endl;
        		double a = pow(pow((x2-x1),2) + pow((y2-y1),2),0.5);
        		temp.cost = a;
        		E.push_back(temp);
//				cout << E[m].st << " " << E[m].en << " " << E[m].cost << endl;
			}
		}
        MST();
    }
}

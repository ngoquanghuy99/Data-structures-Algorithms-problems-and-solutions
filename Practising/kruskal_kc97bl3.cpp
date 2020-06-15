#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int par[230997];
int anc(int p){ if (par[p]==p) return p; else return par[p]=anc(par[p]); }
void join(int p, int q){ par[anc(p)]=anc(q); }

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define X first
#define Y second
vector<iii> edge;
int n, m;

main(){
    int i, p, q, w, r=0;
    scanf("%d%d", &n, &m);
    for (i=1; i<=n; i++) par[i]=i;
    while (m--){
        scanf("%d%d%d", &p, &q, &w);
        edge.push_back(iii(w, ii(p, q)));
    }
    sort(edge.begin(), edge.end());
    vector<iii>::iterator it;
    for (it=edge.begin(); it!=edge.end(); it++){
        if (anc(it->Y.X) != anc(it->Y.Y)){
        	cout << it->Y.X << "___" << it->Y.Y << endl;
            join(it->Y.X, it->Y.Y);
            r += it->X;
        }
    }
    printf("%d\n", r);
}


/*
Author: Ngo Quang Huy
Problem: F

This is contributed by Ngo Quang Huy
*/
#include <bits/stdc++.h>

#define base 1000000007
#define N (int)1e5+7
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define FOR(i, a, b) for(long i = a; i <= b; i++)
#define FO(i, a, b) for(long i = a; i < b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FORV(i, a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define yes cout<<"yes\n";
#define no cout<<"no\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define PI 3.1415926535897
#define lamtron(n) fixed<<setprecision(n)
#define ALL(s) s.begin(),s.end()
#define NUMBER "0123456789"
#define uALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define lALPHA "abcdefghijklmnopqrstuvwxyz"
#define uWb "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define lWb "0123456789abcdefghijklmnopqrstuvwxyz"
#define forn(i,n) for(i=0;i<n;++i)

using namespace std;

typedef pair<int, int> pii;

#define mp make_pair

void solve(){
    int n;
    cin >> n;
    char a[n][n];
    int i, j;
    forn(i, n) forn(j, n) cin >> a[i][j];
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    map<pii, int> visited, path;
    queue<pii> q;
    q.push(mp(x1, y1));
    visited[mp(x1, y1)] = 1;
    path[mp(x1, y1)] = 0;
    int dr[] = { -1, 0, 0, 1 }, dc[] = { 0, -1, 1, 0 };
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
        if (visited[{ x2, y2 }]){
            cout << path[{ x2, y2 }];
            return;
        }
        int r1 = u.first + 1, r2 = u.first - 1, c1 = u.second + 1, c2 = u.second - 1;
        while (r1 < n && a[r1][u.second] == '.' && visited[{ r1, u.second }] == 0){
            visited[{ r1, u.second }] = 1;
            path[{ r1, u.second }] = path[u] + 1;
            q.push({ r1, u.second });
            r1++;
        }
        while (r2 >= 0 && a[r2][u.second] == '.' && visited[{ r2, u.second }] == 0){
            visited[{ r2, u.second }] = 1;
            path[{ r2, u.second }] = path[u] + 1;
            q.push({ r2, u.second });
            r2--;
        }
        while (c1 < n && a[u.first][c1] == '.' && visited[{ u.first, c1 }] == 0){
            visited[{ u.first, c1 }] = 1;
            path[{ u.first, c1 }] = path[u] + 1;
            q.push({ u.first, c1 });
            c1++;
        }
        while (c2 >= 0 && a[u.first][c2] == '.' && visited[{ u.first, c2 }] == 0){
            visited[{ u.first, c2 }] = 1;
            path[{ u.first, c2 }] = path[u] + 1;
            q.push({ u.first, c2 });
            c2--;
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}



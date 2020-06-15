#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        n--;
        cout << n*(n+1)*(n+2)/6 << endl;
    }
    return 0;
}

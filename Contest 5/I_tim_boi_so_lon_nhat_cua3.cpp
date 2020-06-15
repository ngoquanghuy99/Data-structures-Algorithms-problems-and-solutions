/*
Author: Ngo Quang Huy
Problem: I

This is contributed by Ngo Quang Huy
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --){
        int n;
        vector <int>  v[3], ans;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if (x%3 == 0)
                ans.push_back(x);
            else
                v[x%3].push_back(x);
        }
        sort (v[1].begin(), v[1].end(), greater<int>());
        sort (v[2].begin(), v[2].end(), greater<int>());
        if (v[1].size() < v[2].size()){
            if ((v[2].size()-v[1].size())%3 == 2)
                if (v[1].size() > 0)
                    v[1].pop_back();
                else
                    v[2].pop_back(),v[2].pop_back();

            if (v[2].size()-v[1].size() == 1)
                v[2].pop_back();
        }
        if (v[1].size() > v[2].size()){
            if ((v[1].size()-v[2].size())%3 == 2)
                if (v[2].size() > 0)
                    v[2].pop_back();
                else
                    v[1].pop_back(), v[1].pop_back();
            if ((v[1].size()-v[2].size())%3 == 1)
                v[1].pop_back();
        }
        for (int i = 0; i < v[1].size(); i++)
            ans.push_back(v[1][i]);
        for (int i = 0; i < v[2].size(); i++)
            ans.push_back(v[2][i]);
        sort(ans.begin(), ans.end(), greater<int>());
        if (ans.size() == 0)
            cout << -1;
        else{
                if (ans[0] == 0)
                    cout << 0;
                else
                    for (int i = 0; i < ans.size(); i++)
                        cout << ans[i];
            }
        cout << endl;
    }
    return 0;
}


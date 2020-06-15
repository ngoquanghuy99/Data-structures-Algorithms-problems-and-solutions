/*
Author: Ngo Quang Huy
Problem: I - Tong da thuc
*/
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
const int max_def = 10001;
void hand(string s, vector <int> &f){
    stringstream ss;
    ss << s.c_str();
    while (!ss.eof()){
        string tmp;
        ss >> tmp;
        if (tmp == "+") continue;
        int val,def;
        stringstream s2;
        s2 << tmp.c_str();
        char x;
        s2 >> val >> x >> x >> x >> def;
        f[def]+=val;
    }
}
string int2Str(int a){
    stringstream s;
    s << a;
    string tmp;
    s >> tmp;
    return tmp;
}
int main(){
    int test;
    cin >> test;
    cin.ignore();
    while (test--){
        vector <int> fx(max_def+1,0);
        string tmp1,tmp2;
        getline(cin,tmp1);
        getline(cin,tmp2);
        hand(tmp1,fx);
        hand(tmp2,fx);
        string ans;
        for (int i = max_def; i >= 0; i--){
            if (fx[i]){
                ans.append(" + ");
                ans.append(int2Str(fx[i]));
                ans.append("*x^");
                ans.append(int2Str(i));
            }
        }
        ans.erase(0,3);
        cout << ans << endl;
    }
}

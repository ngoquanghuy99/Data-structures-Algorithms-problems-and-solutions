#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <sstream>
#include <map>

#define base 1000000007
#define N (int)1e5 + 7
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FO(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FORV(i, a) for (typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define yes cout << "yes\n";
#define no cout << "no\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define PI 3.1415926535897
#define lamtron(n) fixed << setprecision(n)
#define ALL(s) s.begin(), s.end()
#define NUMBER "0123456789"
#define uALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define lALPHA "abcdefghijklmnopqrstuvwxyz"
#define uWb "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define lWb "0123456789abcdefghijklmnopqrstuvwxyz"


using namespace std;

#define pb push_back

string ConverttoString(long long n)
{
    string ans;
    //thuoc include sstream kha thu vi trong viec chuyen doi
    stringstream str;
    str << n;
    str >> ans;
    return ans;
}

/*tuong tu ve cach chuyen doi cua bai D nhung se phai chuyen doi cach chu so*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i = 0, j;
        string temp = "", ope = "(+-*/)";
        //init do uu tien phep tinh
        map<string, int> priority;
        priority["*"] = 2;
        priority["/"] = 2;
        priority["+"] = 1;
        priority["-"] = 1;
        priority[")"] = 0;
        vector<string> split, tempRes;
        while (i < s.size())
        {
            while (ope.find(s[i]) == string::npos && i < s.size())
            {
                temp += s[i];
                i++;
            }
            if (temp.size())
                split.pb(temp);
            string t = "";
            t += s[i];
            split.pb(t);
            temp = "";
            i++;
        }
        stack<string> st;
        FO(i, 0, split.size())
        {
            string j = split[i];
            if (ope.find(j) == string::npos)
                tempRes.pb(j);
            else if (j == "(")
                st.push(j);
            else if (j == ")")
            {
                while (!st.empty() && st.top() != "(")
                {
                    tempRes.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if (ope.find(j) != string::npos)
            {
                while (!st.empty() && priority[j] <= priority[st.top()])
                {
                    tempRes.pb(st.top());
                    st.pop();
                }
                st.push(j);
            }
        }
        while (!st.empty())
        {
            tempRes.pb(st.top());
            st.pop();
        }
        stack<string> t;
        FO(i, 0, tempRes.size())
        {
            string j = tempRes[i];
            if (isdigit(j[0]))
                t.push(j);
            else if (ope.find(j) != string::npos)
            {
                long long y = atoll(t.top().c_str());
                t.pop();
                long long x = atoll(t.top().c_str());
                t.pop();
                long long z;
                if (j == "*")
                    z = x * y;
                else if (j == "/")
                    z = x / y;
                else if (j == "-")
                    z = x - y;
                else
                    z = x + y;
                t.push(ConverttoString(z));
            }
        }
        cout << t.top() << endl;
    }
    return 0;
}


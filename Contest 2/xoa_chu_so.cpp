#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main (){	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    long N, K;
    cin>>N>>K;
    stack <int> S;
    for (long i=1; i<=N; i++){
        char c;
        cin>>c;
        int num = c - '0';
        if (S.empty())
            S.push(num);
        else{
            while (!S.empty() && num > S.top() && K>0){
                S.pop();
                K--;
            }
            S.push(num);
        }
    }
    while (K>0 && !S.empty()){
        S.pop();
        K--;
    }
    vector <int> smallest;
    while (!S.empty()){
        int tmp=S.top();
        S.pop();
        smallest.push_back(tmp);
    }
    for (long i=smallest.size()-1; i>=0; i--)
        cout<<smallest[i];
    return 0;
}

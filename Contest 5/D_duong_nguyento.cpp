#include<iostream>
#include<queue>
#include<string.h>
#define max 10005
using namespace std;
int T, s, d, digit[4];
int prime[max], dist[max];
void sieve(){
    for (int i = 2; i < 10000; i++){
        if (prime[i]){
            int num = i;
            for (int j = 2; num*j <=max; j++)
                prime[num*j] =0;
        }
    }
}
void num_to_arr(int value[], int num){
    for (int i = 3; i >= 0; i--){
        value[i] = num % 10;
        num /= 10;
    }
}
int arr_to_num(int value[]){
    int res = 1000 * value[0] + 100 * value[1] + 10 * value[2] + value[3];
    return res;
}
int main(){
    memset(prime, -1, sizeof(prime));
    sieve();
    cin >> T;
    while (T--){
        cin >> s >> d;
        memset(dist, -1, sizeof(dist));
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty()){
            s = q.front();
            q.pop();
            for (int i = 0; i <= 3; i++){
                num_to_arr(digit, s);
                for (int j = 0; j <= 9; j++){
                    digit[i] = j;
                    int temp = arr_to_num(digit);
                    if (prime[temp] == -1 && temp > 1000 && dist[temp] == -1){
                        dist[temp] = dist[s] + 1;
                        q.push(temp);
                    }
                }
            }
        }
        if (dist[d] == -1)
            cout << "Impossible" << endl;
        else
            cout << dist[d] << endl;
    }
    return 0;
}

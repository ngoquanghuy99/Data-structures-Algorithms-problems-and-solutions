/*
Author: Ngo Quang Huy
Problem: K - phan tu ben phai dau tien lon hon
*/
#include <iostream>
#include <stack>
using namespace std;
int main() {
	int t = 0;
	cin >> t;
	while(t--){
	    int n;
	    stack <int> s;
	    cin >> n;
	    int arr[n], ans[n];
	    for(int i = 0; i < n; ++i)
	        ans[i] = -1;
	    for(int i = 0; i < n; ++i)
	        cin >> arr[i];
	        
	    for(int i = 0; i < n; ++i){
	            while(!s.empty() && arr[i] > arr[s.top()]){
	                int a = s.top();
	                s.pop();
	                ans[a] = arr[i];
	            }
	        s.push(i);
	    }
	    for(int i = 0; i < n; ++i)
	        cout << ans[i] << " ";
	    cout << endl;
	}
	  
    return 0;
}

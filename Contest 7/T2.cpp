// C++ program for finding postorder
// traversal of BST from preorder traversal
#include <bits/stdc++.h>
using namespace std;

int find(int pre[], int n){
    int i=0;
    while(i<n-1 && pre[i+1]<pre[0])
       ++i;
    return i;
}

// Function to find postorder traversal.
void findPostOrder(int pre[], int n)
{
    if(n<=0)
       return;
    if(n==1){
        cout<<pre[0]<<" ";
        return;
    }
    int root=pre[0];
    int i=find(pre,n);
    if(i!=0)
       findPostOrder(pre+1,i);
    findPostOrder(pre+i+1,n-i-1);
    cout<<root<<" ";
}

// Driver code
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		int pre[10005];
		for(int i=0;i<n;i++) cin>>pre[i];
   		findPostOrder(pre, n);
   		cout << endl;
	}
	return 0;
}


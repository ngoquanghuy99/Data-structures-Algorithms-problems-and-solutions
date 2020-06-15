#include <bits/stdc++.h>
using namespace std;
 
int find(int pre[],int n){
	for(int i=1;i<n;i++) if(pre[i]>pre[0]) return i;
	return n;
}

void postorder_of_BST(int pre[],int n){
	if(n>1){
		int pos = find(pre,n);
		postorder_of_BST(pre+1,pos-1);
		postorder_of_BST(pre+pos,n-pos);
		
	}
	if(n>0) cout<<pre[0]<<" ";
}

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		int pre[10005];
		for(int i=0;i<n;i++) cin>>pre[i];
   		postorder_of_BST(pre,n);
   		cout << endl;
	}

	return 0;
}

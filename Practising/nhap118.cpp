// 118
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

node *make(int a){
	node *temp = new node;
	temp->data = a;
	temp->left = NULL;
	temp->right = NULL;
}

node *insert(node *root, int a){
	if(root == NULL) return make(a);
	if(a < root->data) root->left = insert(root->left, a);
	else root->right = insert(root->right, a);
	return root;
}

void printLeafnodes(node *root){
	if(root == NULL) return;
	if(!root->left && !root->right){
		cout << root->data << " ";
		return;
	} 
	if(root->left) printLeafnodes(root->left);
	if(root->right) printLeafnodes(root->right);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n; int a[n+1];
		node *root = NULL;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			root = insert(root, a[i]);
		}
		printLeafnodes(root); cout << endl;
	}
	return 0;
}

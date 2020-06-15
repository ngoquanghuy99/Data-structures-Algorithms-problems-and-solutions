#include <iostream>
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

int counting(node *root){
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	return 1 + counting(root->left) + counting(root->right);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n; int a[n+5];
		node *root = NULL;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			root = insert(root, a[i]);
		}
		cout << counting(root) << endl;
	}
	return 0;
}

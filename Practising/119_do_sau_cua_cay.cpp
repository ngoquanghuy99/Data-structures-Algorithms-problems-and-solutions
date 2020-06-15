#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

node *Make_Node(int a){
	node *temp = new node;
	temp->data = a;
	temp->left = NULL;
	temp->right = NULL; 
}

node *Insert_Node(node *root, int a){
	if(root == NULL) return Make_Node(a);
	
	if(a < root->data) root->left = Insert_Node(root->left, a);
	
	else root->right = Insert_Node(root->right, a);
	
	return root;
}

int Deep(node *root){
	if(root == NULL) return 0;
	int l, r;
	l = Deep(root->left);
	r = Deep(root->right);
	
	if(l < r) return r + 1;
	else return l + 1;
}

int main(){
	int time;
	cin >> time;
	while(time--){
		int n; cin >> n;
		int a[n+5];
		node *root = NULL;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			root = Insert_Node(root, a[i]);
		}
		cout << Deep(root) - 1 << endl;
	}
}

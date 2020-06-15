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
	if(!root) return make(a);
	if(a < root->data) root->left = insert(root->left, a);
	else root->right = insert(root->right, a);
	return root;
}

void pre(node *root){
	if(root){
		cout << root->data << " ";
		pre(root->left);
		pre(root->right);
	}
}
void inpo(node *root){
	if(root){
		inpo(root->left);
		cout << root->data << " ";
		inpo(root->right);
	}
}

void post(node *root){
	if(root){
		post(root->left);
		post(root->right);
		cout << root->data << " ";
	}
}

node *minleftnode(node *root){
	node *current = root;
	while (current->left) current = current->left;
	return current;
}

node *deletenode(node *root, int a){
	if(!root) return root;
	if(a < root->data) root->left = deletenode(root->left, a);
	else if(a > root->data) root->right = deletenode(root->right, a);
	else{
		if(!root->left){
			node *t = root->right;
			return t;
		}
		else if(!root->right){
			node *t = root->left;
			return t;
		}
		node *temp = minleftnode(root->right);
		root->data = temp->data;
		root->right = deletenode(root->right, temp->data);
	}
	return root;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	node *root = NULL;
	int cmd = 0; 
	do{
		cin >> cmd;
		if(cmd == 1){
			int temp = 0; cin >> temp;
			root = insert(root, temp);
		}
		else if(cmd == 2){
			int temp = 0; cin >> temp;
			root = deletenode(root, temp);
		}
	} while (cmd != 3);
	pre(root); cout << endl;
	inpo(root); cout << endl;
	post(root); cout << endl;
	return 0;
}

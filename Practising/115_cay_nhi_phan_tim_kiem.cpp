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

void Pre_Order(node *root){
	if(root != NULL){
		cout << root->data << " ";
		Pre_Order(root->left);
		Pre_Order(root->right);
	}
}

void In_Order(node *root){
	if(root != NULL){
		In_Order(root->left);
		cout << root->data << " ";
		In_Order(root->right);
	}
}

void Post_Order(node *root){
	if(root != NULL){
		Post_Order(root->left);
		Post_Order(root->right);
		cout << root->data << " ";
	}
}

node *minNodeLeft(node *root){
	node *current = root;
	while(current->left != NULL) current = current->left;
	
	return current;
}

node *DeleteNode(node *root, int a){
	if(root == NULL) return root;
	
	if(a < root->data) root->left = DeleteNode(root->left, a);
	else if(a > root->data) root->right = DeleteNode(root->right, a);
	else{
		if(root->left == NULL){
			node *temp = root->right;
//			free(root);
			return temp;
		}
		
		else if(root->right == NULL){
			node *temp = root->left;
//			free(root);
			return temp;
		}
		
		node *temp = minNodeLeft(root->right);
		root->data = temp->data;
		root->right = DeleteNode(root->right, temp->data);
	}
	return root;
}

int main(){
	node *root = NULL;
	int cmd;
	do{
		cin >> cmd;
		if(cmd == 1){
			int temp;
			cin >> temp;
			root = Insert_Node(root, temp);
		}
		if(cmd == 2){
			int temp;
			cin >> temp;
			root = DeleteNode(root, temp);
		}
	}while(cmd != 3);
	Pre_Order(root); cout << endl;
	In_Order(root); cout << endl;
	Post_Order(root); cout << endl;
}

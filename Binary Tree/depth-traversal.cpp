//Binary tree program - C++
//Depth first traversal - In Order, Pre Order, Post Order
//Sanjeev Sharma

#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* new_node(int item){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = item;
	new_node->left = NULL;
	new_node->right = NULL;

	cout << "Node created with data = " << item << "." << endl;

	return new_node;
}

void preOrder(struct Node* tree){
	if (tree == NULL) return;
	
	cout << tree->data << " ";	
	
	preOrder(tree->left);

	preOrder(tree->right);
}

void inOrder(struct Node* tree){
	if (tree == NULL) return;	
	
	inOrder(tree->left);

	cout << tree->data << " ";

	inOrder(tree->right);
}

void postOrder(struct Node* tree){
	if (tree == NULL) return;	
	
	postOrder(tree->left);

	postOrder(tree->right);

	cout << tree->data << " ";
}

int main(){

	struct Node* root = new_node(1);

	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	
// 	1   --root
//     / \
//    2   3
//   / \
//  4   5

	cout << "Printing In-Order..." << endl;
	inOrder(root);
	cout << endl;
	cout << "Printing Pre-Order..." << endl;
	preOrder(root);
	cout << endl;
	cout << "Printing Post-Order..." << endl;
	postOrder(root);
	cout << endl;

	return 0;
}


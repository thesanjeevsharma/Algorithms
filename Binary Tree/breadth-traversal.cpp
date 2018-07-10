//Binary tree program - C++
//Breadth first traversal
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

void printLevel(struct Node* root, int level){
	if (root==NULL) return;

	if (level == 1) cout << root->data << " ";
	else if(level > 1){
		printLevel(root->left, level-1);
		printLevel(root->right, level-1);
	}
}

int height(struct Node* root){
	if(root == NULL) return 0;
	else{
		int lh = height(root->left);
		int rh = height(root->right);

		if(lh > rh) return (lh + 1);
		else return (rh + 1);
	}
}


void traverse(struct Node* root){
	int h = height(root);
	
	for(int i = 1; i <= h; i++){
		printLevel(root, i);
	}
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

	cout << "Printing Breadth First Order..." << endl;
	traverse(root);
	cout << endl;

	return 0;
}


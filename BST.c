// C++ program to check if a given tree is BST. 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to 
left child and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// Returns true if given tree is BST. 
bool isBST(Node* root, Node* l=NULL, Node* r=NULL) 
{
	if (root == NULL)
		return true;
	if (l != NULL && root->data <= l->data)
		return false;
	if (r != NULL && root->data >= r->data)
		return false;
	return (isBST(root->left, l, root) && isBST(root->right, root, r));
} 


bool isBST2(Node* root)
{
	static int prev = INT_MIN;
	if(root != NULL) {
		if(!isBST2(root->left))
			return false;
		if(root->data >= prev)
			return false;
		prev = root->data;
		return isBST2(root->right);

	}
	return true;
	
}

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = newNode(3); 
	root->left	 = newNode(2); 
	root->right	 = newNode(5); 
	root->left->left = newNode(1); 
	root->left->right = newNode(4); 

	if (isBST(root,NULL,NULL)) 
		cout << "Is BST" << endl; 
	else
		cout << "Not a BST" << endl; 

	if (isBST2(root)) 
		cout << "Is BST" << endl; 
	else
		cout << "Not a BST" << endl; 

	return 0; 
} 


#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* cretnewNode(int data)
{
	// Allocate memory for new node  
	struct node* node = (struct node*)malloc(sizeof(struct node));
	// Assign data to this node 
	node->data = data;
	// Initialize left and right children as NULL 
	node->left = NULL;
	node->right = NULL;
	return(node);
}
struct node*insert(struct node * temp, int key) {
	/* If the tree is empty, return a new node */
	if (temp == NULL)
		return cretnewNode(key);
	/* Otherwise, recur down the tree */
	if (key < temp->data)
		temp->left = insert(temp->left, key);
	else if (key > temp->data)
		temp->right = insert(temp->right, key);
	/* return the (unchanged) node pointer */
	return temp;
}
struct node*searsh(struct node*temp, int data) {
	// Base Cases : temp is null or key is present at root
	if (temp == NULL) {
		return temp;
	}
	//Key is greater than temp's key 
	if (temp->data < data)
		return insert(temp->right, data);
	//Key is smaller than temp's key 
	return insert(temp->left, data);
}
void main() {
	struct node*root = NULL;
	root = insert(root, 5);
	insert(root, 4);
	insert(root, 6);
	insert(root, 9);
	searsh(root, 6);
	getchar();
}
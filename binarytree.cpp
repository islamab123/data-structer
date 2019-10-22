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
int min_value(struct node*node) {
	struct node* current = node;
	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
	{
		current = current->left;
	}
	return(current->data);
}
int max_value(struct node*node) {
	struct node* current = node;
	/* loop down to find the rightmost leaf */
	while (current->right != NULL)
	{
		current = current->right;
	}
	return(current->data);
}
int print_inorder(struct node*node) {
	if (node == NULL)
		return 0;
	else {
		/* first recur on left child */
		print_inorder(node->left);

		/* then print the data of node */
		printf("%d ", node->data);

		/* now recur on right child */
		print_inorder(node->right);
	}
}
int print_postorder(struct node*node) {
	if (node == NULL)
		return 0;
	else {
		// first recur on left subtree 
		print_postorder(node->left);

		// then recur on right subtree 
		print_postorder(node->right);

		// now deal with the node 
		printf("%d ", node->data);
	}
}
int max_depth(struct node*node) {
	if (node == NULL)//If tree is empty then return 0
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int l_depth = max_depth(node->left);// Get the max depth of left subtree recursively 
		int r_depath = max_depth(node->right);//Get the max depth of right subtree recursively

											  /* use the larger one */
		if (l_depth > r_depath)
			return(l_depth + 1);
		else return(r_depath + 1);
	}
}
void main() {
	int min = 0,max=0, max_length;
	struct node*root = NULL;
	root = insert(root, 5);
	insert(root, 4);
	insert(root, 6);
	insert(root, 9);
	searsh(root, 6);
	min = min_value(root);
	printf("\n  the min value in this binary tree is :  %d", min);
	max = max_value(root);
	printf("\n  the max value in this binary tree is : %d", max);
	printf("the inorder print :\n");
	print_inorder(root);
	printf("\nthe postorder print :\n");
	print_postorder(root);
	max_length = max_depth(root);
	printf("\n  the max depath of this binary tree is : %d ", max_length);
	getchar();
}
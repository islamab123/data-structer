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
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
struct node*insert(struct node * temp, int key) {
	if (temp == NULL)
		return cretnewNode(key);
	if (key < temp->data)
		temp->left = insert(temp->left, key);
	else if (key > temp->data)
		temp->right = insert(temp->right, key);
	return temp;
}
struct node*searsh(struct node*temp, int data) {
	if (temp == NULL) {
		return temp;
	}
	if (temp->data < data)
		return insert(temp->right, data);
	return insert(temp->left, data);
}
int min_value(struct node*node) {
	struct node* current = node;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return(current->data);
}
int max_value(struct node*node) {
	struct node* current = node;
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
		print_inorder(node->left);
		printf("%d ", node->data);
		print_inorder(node->right);
	}
}
int print_postorder(struct node*node) {
	if (node == NULL)
		return 0;
	else {
		print_postorder(node->left);
		print_postorder(node->right);
		printf("%d ", node->data);
	}
}
int max_depth(struct node*node) {
	if (node == NULL)
		return 0;
	else
	{
		int l_depth = max_depth(node->left);
		int r_depath = max_depth(node->right);

		if (l_depth > r_depath)
			return(l_depth + 1);
		else return(r_depath + 1);
	}
}
bool if_full(struct node*node) {
	if (node == NULL) {
		return false;
	}
	if (max_depth(node->left) == max_depth(node->right)) {
		return if_full(node->left) && if_full(node->right);
	}return false;
}
bool if_complete(struct node*node) {
	if (node == NULL) {
		return false;
	}
	if (max_depth(node->left) != max_depth(node->right)) {
		return true;
	}return false;
}
int if_identical(struct node*root, struct node*temp) {
	if (root == NULL&&temp == NULL) {
		return 1;
	}
	if (root != NULL&&temp != NULL) {
		if (root->data == temp->data) {
			return(if_identical(root->left, temp->left) && if_identical(root->right, temp->right));
		}
	}
	return 0;

}
void main() {
	int min = 0, max = 0, max_length, identical;
	struct node*root = NULL;
	struct node*temp = NULL;
	root = insert(root, 10);
	insert(root, 5);
	insert(root, 12);
	insert(root, 4);
	insert(root, 6);
	temp = insert(temp, 10);
	insert(temp, 45);
	insert(temp, 4);
	insert(temp, 4);
	insert(temp, 6);
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
	if (if_full(root)) {
		printf("\nis full\n");
	}
	if (if_complete(root)) {
		printf("\nis comblete\n");
	}
	identical = if_identical(root, temp);
	if (identical == 0) {
		printf("\nthe two trees are not identical\n");
	}
	else
		printf("\nthe two trees are identical\n");

	getchar();
}
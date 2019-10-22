#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* cretnewNode(int data) {
	// Allocate memory for new node  
	struct node*node = (struct node*)malloc(sizeof(struct node));
	// Assign data to this node 
	node->data = data;
	printf(" %d ", data);
	// Initialize left and right children as NULL 
	node->left = NULL;
	node->right = NULL;
	return node;
}
void main() {
	struct node*root = NULL;
	root = cretnewNode(5);
}
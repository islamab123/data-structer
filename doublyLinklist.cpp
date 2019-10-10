#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node*next;
};
struct node*head;
struct node*createnewnode(int x) {
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head;
}
void inserttohead(int x) {}
void append(int x) {
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
}
void print() {
	struct node*temp = head;
	while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
bool isempty() {
	if (head == NULL) {
		return true;
	}
	else return false;
}
int length() {
	int length = 0;
	struct node*temp = head;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}
	return length;
}
void main() {
	head = NULL;
	int len;
	inserttohead(1);
	inserttohead(2);
	print();
	len = length();
}

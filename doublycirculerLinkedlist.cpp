#include <stdio.h>
#include <stdlib.h>
struct crculer_likedlist;
struct node {
	int data;
	struct node*next;
};
struct node*head;
void cerculer_newvalue(int x) {
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
}
void append(int x) {
	struct node * temp = (struct node*)malloc(sizeof(struct node));
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
int  searsh(int x) {
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	while (temp != NULL) {
		if (temp->data == x) {
			return temp->data;

		}
		else temp = temp->next;
	}
}
void update(int oldvalue, int newvalue) {
	struct node*temp = head;
	while (temp != NULL) {
		if (temp->data == oldvalue) {
			temp->data = newvalue;
		}
		else temp = temp->next;
	}
}
void deletenodeatposition(int position) {
	struct node*temp = head;
	int c = 0;
	while (temp->next != NULL) {
		c++;
		if (c == (position - 1)) {
			temp->next = temp->next->next;
		}
		temp = temp->next;
	}
}
void sort() {}
void insertatposition(int newvalue, int position) {
	struct node*temp = head;
	int c = 0, flag = 0;
	while (flag == 0) {
		if (temp != NULL) {
			c++;
			if (c == position) {
				struct node*newnode = (struct node*)malloc(sizeof(struct node));
				struct node*prev_temp = temp;
				temp = newnode;
				temp->data = newvalue;
				temp->next = prev_temp;

				flag = 1;
			}
		}
		else temp = temp->next;
	}head = temp;
}
void main() {
	struct node*head = NULL;
	cerculer_newvalue(10);
	append(12);
	append(23);
	print();
	deletenodeatposition(2);
	update(12, 15);
	searsh(12);
	print();
}
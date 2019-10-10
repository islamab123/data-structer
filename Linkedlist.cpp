#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node*head;
struct node*append(int x) {
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head;
}
void isertathead(int x) {
	append(x);
}
void insertatposition(int x, int position) {
	struct node*temp = head;
	int c = 0, flag = 0;
	while (flag == 0) {
		if (temp != NULL) {
			c++;
			if (c == position) {
				struct node*newnode = (struct node*)malloc(sizeof(struct node));
				node*prev_temp = temp;
				temp = newnode;
				temp->data = x;
				temp->next = prev_temp;

				flag = 1;
			}
		}
		else temp = temp->next;
	}head = temp;
}
void deleteatposition(int position) {
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
void print() {
	struct node*temp = head;
	while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	getchar();
}
void reverse() {}
void main() {
	head = NULL;
	int i, num, x;
	printf("how many nodes ?\n");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		printf(" enter the number\n");
		scanf_s("%d", &x);
		append(x);
	}
	isertathead(10);
	insertatposition(5, 1);
	print();
	deleteatposition(2);
	print();
	getchar();

}


#include <stdio.h>
#include <stdlib.h>
struct node{

	struct node * next;
	int data;
};
struct node*head;//globel var 

struct node*Insert(int x) {
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head;
}
/*void tail_to_lingth(node*tail,int value){
struct node*temp = head;
int flag = 0;
while (flag == 0) {
if (temp->next == NULL) {
temp->data = value;
head->next = temp->next;
flag = 1;
}
else {
temp = temp->next;
}
}

while (temp != NULL) {
printf("the number you add to the last of the struct is  %d ", temp->data);
temp = temp->next;
}
//printf("\n");

  getchar();

  }*/
int insert_between(int x, int y) {// x is the index , y is the value i wann add
	struct node*temp = head;
	int c = 0, flag = 0;
	while (flag == 0) {
		if (temp->next != NULL) {
			c++;
			if (c == x) {
				struct node*h = (struct node*)malloc(sizeof(struct node));
				temp->next = h;
				h->data = y;
				h->next = temp->next->next;
				flag = 1;
			}
		}
		else temp = temp->next;
	}
	getchar();
	return y;
}
void print() {
	struct node*temp = head;
	while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void main() {
	head = NULL;

	Insert(3);
	print();
	int i, num;
	printf("how many nodes ?\n");
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		printf(" enter the number\n");
		scanf("%d", &head->data);
	}
	//printf(" enter a number you wanna add to the last of the struct  \n ");
	//scanf_s("%d", &num2);
	//tail_to_lingth(head,num2);
	insert_between(5, 8);

	getchar();



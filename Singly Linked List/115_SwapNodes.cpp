#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
void swapNodes(struct Node **headRef, int x, int y) {
	if (x == y) {
		return;
	} 
	Node *prevX = NULL;
	Node *currentX = *headRef;
	while (currentX && currentX->data != x ) {
		prevX = currentX;
		currentX = currentX->next;
	}
	Node *prevY = NULL;
	Node *currentY = *headRef;
	while (currentY && currentY->data != y ) {
		prevY = currentY;
		currentY = currentY->next;
	}
	if (currentX == NULL || currentY == NULL) {
		return;
	}

	if (prevX != NULL) {
		prevX->next = currentY;
	} else {
		*headRef = currentY;
	}

	if (prevY != NULL) {
		prevY->next = currentX;
	} else {
		*headRef = currentX;
	}
	Node *temp = currentY->next;
	currentY->next = currentX->next;
	currentX->next = temp;
}

void printList(struct Node *node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

void append(struct Node **headRef, int data) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	newNode->data = data;
	newNode->next = NULL;
	if (*headRef == NULL) {
		*headRef = newNode;
	return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newNode;
	return;
}

int main () {
	struct Node *head = NULL;
	append(&head, 6);
	append(&head, 5);
	append(&head, 12);
	append(&head, 8);
	append(&head, 9);
	append(&head, 13);
	cout << "List: ";
	printList(head);
	swapNodes(&head, 6 , 8);
	cout << "List after swapping Nodes: ";
	printList(head);
	return 0;
}	
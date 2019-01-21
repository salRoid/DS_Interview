/**
    Problem: Inserting a node after the given node of Linked List

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next; 
};

void printList(struct Node *node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next; 
	}
	cout << "\n"; 
}

void push (struct Node **headRef, int data) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

void insertAfter(struct Node *prevNode, int data) {
	if (prevNode == NULL) {
		cout << "Previous Node can't be NULL. \n";
		return;
	}
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

int main () {
	
	struct Node* head = NULL;
	push(&head, 3);
	push(&head, 4);
	insertAfter(head->next, 6);
	push(&head, 7);
	insertAfter(head->next->next, 5);
	cout << "List: ";
	printList(head);

	return 0;
}
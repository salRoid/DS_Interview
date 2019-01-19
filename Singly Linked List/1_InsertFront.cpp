/**
    Problem: Inserting a node in the front of Linked List

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void printList(struct Node *node ) {
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
	cout << "\n";
}

void push(struct Node **headRef, int data) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

int main () {
	struct Node* head = NULL;
	push(&head, 6);
	push(&head, 7);
	push(&head, 5);
	cout << "List: ";
	printList(head);
	return 0;
}
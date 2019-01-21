/**
    Problem: Inserting a node at the end of Linked List

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void printList (struct Node *node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

void append(struct Node **headRef, int data) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
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
	append(&head, 7);
	append(&head, 5);
	cout << "List: ";
	printList(head);
	return 0;
}
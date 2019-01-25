/**
    Problem: Search an element in Linked List

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void append(struct Node **headRef, int data) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	struct Node *last = *headRef;
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

bool searchIterative (struct Node *head, int data) {
	struct Node *current = head;
	while (current != NULL) {
		if (current->data == data) {
			return true;
		}
		current = current -> next;
	}
	return false;
}

bool searchRecursive (struct Node *head, int data) {
	if (head == NULL) 
		return false;	
	if (head->data == data) 
		return true;
	return searchRecursive(head->next, data);
}	


int main () {
	struct Node *head = NULL;
	append(&head, 6);
	append(&head, 7);
	append(&head, 4);
	append(&head, 3);
	append(&head, 1);
	cout << "List: ";
	printList(head);
	cout << "Iterative: " << searchIterative(head, 6) << "\n";
	cout << "Iterative: " << searchIterative(head, 5) << "\n";
	cout << "Recursive: " << searchRecursive(head, 1) << "\n";
	cout << "Recursive: " << searchRecursive(head, 2) << "\n";
	return 0;
}
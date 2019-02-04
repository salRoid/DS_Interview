/**
    Problem: Delete a Linked List

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void printList(struct Node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void deleteList(struct Node **headRef) {
	struct Node *current = *headRef;
	struct Node *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*headRef = NULL;
}

void append(struct Node **headRef, int data) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
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

int main () {
	struct Node *head = NULL;
	append(&head, 5);
	append(&head, 6);
	append(&head, 7);
	append(&head, 1);
	cout << "Created List: ";
	printList(head);
	deleteList(&head);
	cout << "List After Deletion: ";
	printList(head);
	return 0;
}
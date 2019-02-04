/**
    Problem: Delete a linked list node at a given postion.

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

void deleteNode(struct Node **headRef, int position) {
	if (*headRef == NULL) {
		return;
	}
	struct Node *temp = *headRef;
	if (position == 0) {
		*headRef = temp->next;
		free(temp);
		return;
	}
	for (int i = 0; i < position - 1; i++) {
		temp = temp-> next;
		if (temp == NULL || temp->next == NULL) {
			return;
		}
		struct Node *nextNode = temp->next->next;
		free(temp->next);
		temp->next = nextNode;
	}
}

int main () {
	struct Node *head = NULL;
	append(&head, 2);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	cout << "Create List: ";
	printList(head);
	deleteNode(&head, 2);
	cout << "List After Deletion: ";
	printList(head);
	return 0;
}
/**
    Problem: Get Nth Node from front in a Linked List

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

void push(struct Node **headRef, int data) {
	struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

int getNodebyIndex(struct Node *head, int index) {
	struct Node *current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index) {
			return current->data;
		}
		count++;
		current = current->next;
	}
	assert(0);
}

int main () {
	struct Node *head = NULL;
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 2);
	cout << "List: ";
	printList(head);
	cout << "Value at index 2: " << getNodebyIndex(head, 2) << endl;
	return 0;
}
/**
    Problem: find the length of the loop.

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void append(struct Node** headRef, int data) {
	struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
	struct Node* last = *headRef;
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

int countNodes (struct Node* loopNode) {
	int count = 1;
	struct Node* temp = loopNode;
	while (temp->next != loopNode ) {
		count++;
		temp = temp->next;
	}
	return count;
}

int detectAndLoopCount(struct Node* head) {
	struct Node* fast = head;
	struct Node* slow = head;

	while ((slow != NULL) && (fast != NULL) && (fast->next != NULL)) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			return countNodes(slow);
		}
	}
	return 0;
}

int main () {
	struct Node* head = NULL;
	append(&head, 7);
	append(&head, 4);
	append(&head, 3);
	append(&head, 2);
	head->next->next->next->next = head;
	cout << detectAndLoopCount(head) << "\n";
	return 0;
}
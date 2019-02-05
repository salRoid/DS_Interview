/**
    Problem: Detecting loop in a Linked List
    a. Mark Visited Nodes (detectLoopUsingHash)
    b. Floyd Cycle Algorithm (detectLoopUsingPointer)

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node* head) {
	while (head == NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void append(struct Node** headRef, int data) {
	struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
	struct Node* last = *headRef;
	newNode->data = data;
	newNode->next = NULL;
	if (*headRef == NULL) {
		*headRef = newNode;
		return;
	}
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = newNode;
	return;
}

bool detectLoopUsingHash(struct Node* head) {
	set<Node *> listFound;
	while (head != NULL) {
		if (listFound.find(head) != listFound.end()) {
			return true;
		} else {
			listFound.insert(head);
		}
		head = head->next;
	}
	return false;
}

bool detectLoopUsingPointer (struct Node* head) {
	struct Node* fast = head;
	struct Node* slow = head;
	while ((slow != NULL) && (fast != NULL) && (fast->next != NULL)) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

int main () {
	struct Node* head = NULL;
	append(&head, 6);
	append(&head, 5);
	append(&head, 3);
	append(&head, 4);
	head->next->next->next->next = head;
	if(detectLoopUsingHash(head)) {
		cout << "Loop Found using hash \n";
	} else {
		cout << "No Loop Found using hash \n";
	}

	if(detectLoopUsingPointer(head)) {
		cout << "Loop Found using fast & slow ptr \n";
	} else {
		cout << "No Loop Found using fast & slow ptr \n";
	}
	
	return 0;
}
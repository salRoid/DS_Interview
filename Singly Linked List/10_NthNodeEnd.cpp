/**
    Problem: Get the Nth node from end in a linked list.
	a. Using Total Nodes (getNodeFromEnd)
	b. Using Two Pointers (getNodeUsingRefPtr)
    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void printList(struct Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
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
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = newNode;
	return;
}

int getNodeFromEnd(struct Node *head, int index) {
	int length = 0;
	struct Node *temp = head;
	while (temp != NULL) {
		temp = temp->next;
		length++;
	}
	if (length < index)
		return -1;
	temp = head;
	for (int i = 1; i < (length - index + 1); i++ ) {
		temp = temp->next;
	}
	return temp->data;
}

int getNodeUsingRefPtr(struct Node *head, int index){
	struct Node *root = head;
	struct Node *ref = head;
	int count = 0;
	if (head != NULL) {
		while (count < index) {
			if (ref == NULL) {
				return -1;
			}
			count++;
			ref = ref->next;
		}	
		while(ref != NULL) {
			root = root->next;
			ref = ref->next;
		}
		return root->data;
	}
}

int main () {
	struct Node *head = NULL;
	append(&head, 5);
  	append(&head, 6);
  	append(&head, 7);
  	append(&head, 2);
  	append(&head, 4);
  	cout << "List: ";
  	printList(head);
  	cout << "2nd Node from End: " << getNodeFromEnd(head, 2) << "\n";
	cout << "3rd Node from End: " << getNodeUsingRefPtr(head, 3) << "\n";
	return 0;
}

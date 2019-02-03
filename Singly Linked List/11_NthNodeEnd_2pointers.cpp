/**
    Problem: 

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
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void append (struct Node **headRef, int data) {
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

int getNodeFromIndex(struct Node *head, int index){
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
	append(&head, 6);
	append(&head, 5);
	append(&head, 1);
	append(&head, 3);
	append(&head, 7);
	cout << "List: ";
	printList(head);
	cout << "2nd Node from End: " << getNodeFromIndex(head, 2) << "\n";
	return 0;
}
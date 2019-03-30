/**
    Problem: Check if Singly Linked List is palindrome
    a. Using Stack (isPalindromeUsingStack)
    b. Using Recursion (isPalindromeUsingRecursion)

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void pritnList(struct Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void append(struct Node** headRef, int data) {
	struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
	struct Node* last= *headRef;
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

bool isPalindromeUsingStack(struct Node* head) {
	stack <int> nodes;
	struct Node* temp = head;
	while (head != NULL) {
		nodes.push(head->data);
		head = head->next;
	}
	while (temp != NULL) {
		if (temp->data == nodes.top()) {
			nodes.pop();
		} else {
			return false;
		}
		temp = temp->next;
	}
	if (nodes.empty() && temp == NULL) {
		return true;
	}
}

bool isPalindromeUsingRecursion (struct Node** left, struct Node* right) {
	if (right == NULL) {
		return true;
	} 
	bool subListCheck = isPalindromeUsingRecursion(left, right->next);
	if (subListCheck == false) {
		return false;
	}
	bool ValueCheck =  (right->data == (*left)->data);
	*left = (*left)->next;
	return ValueCheck;
}

int main () {
	struct Node* head = NULL;
	append(&head, 4);
	append(&head, 1);
	append(&head, 3);
	append(&head, 1);
	append(&head, 4);
	
	cout << "List: ";
	pritnList(head);
	if (isPalindromeUsingStack(head)) {
		cout << "Is Palindrome \n";
	} else {
		cout << "Is Not Palindrome \n";
	}

	append(&head, 5);
	cout << "List: ";
	pritnList(head);
	if (isPalindromeUsingRecursion(&head, head)) {
		cout << "Is Palindrome \n";
	} else {
		cout << "Is Not Palindrome \n";
	}
	return 0;
}

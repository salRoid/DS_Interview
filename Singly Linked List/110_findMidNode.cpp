/**
    Problem: find the middle of linked list
    a. Count and return count/2 (findMidUsingCount)
    b. Two pointer fast and slow (findMidUsingPtr)
    c. Move next when count is odd (findMidUsingMove)

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
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void append(struct Node** headref, int data) {
	struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	struct Node* last = *headref;
	if (*headref == NULL) {
		*headref = newNode;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newNode;
	return;
}

void findMidUsingCount(struct Node* head) {
	int count = 0;
	struct Node* current = head;
	if (head != NULL) {
		while(head != NULL) {
			head = head->next;
			count++;
		}
		int index = 0;
		while (index < (count/2)) {
			current = current->next;
			index++;
		}
		cout << "Mid Node Using Total Node Count: " << current->data << "\n";
	} else {
		cout << "Not Enough Nodes. \n";  
	}
}

void findMidUsingPtr(struct Node* head) {
	struct Node* fast = head;
	struct Node* slow = head;
	if (head != NULL) {
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		cout << "Mid Node Using Slow Fast PTR: " << slow->data << "\n";
	} else {
		cout << "Not Enough Nodes. \n"; 
	}
}

void findMidUsingMove(struct Node* head) {
	struct Node* mid = head;
	int count = 0;
	while (head != NULL) {
		if ((count % 2) != 0) {
			mid = mid->next;
		}
		count++;
		head = head->next;
	}
	if (mid != NULL) {
		cout << "Mid Node Using Odd move: " << mid->data << "\n";
	} else {
		cout << "Not Enough Nodes. \n"; 
	}
}

int main () {
	struct Node* head = NULL;
	append(&head, 6);
	append(&head, 5);
	append(&head, 3);
	append(&head, 4);
	append(&head, 1);
	append(&head, 7);
	cout << "List: ";
	printList(head);
	findMidUsingCount(head);
	findMidUsingPtr(head);
	findMidUsingMove(head);
	return 0;
}
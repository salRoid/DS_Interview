/**
    Problem: Count node in a linked list 
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
 
void append (struct Node **headRef, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
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
 
int getCountIterative (struct Node *head) {
  int count = 0;
  while (head != NULL) {
    count++;
    head = head->next;
  }
  return count;
}
 
int getCountRecursive (struct Node *head) {
  if (head == NULL) {
    return 0;
  }
  return 1 + getCountRecursive(head->next);
}
 
int main() {
  struct Node *head = NULL;
  append(&head, 5);
  append(&head, 6);
  append(&head, 7);
  append(&head, 2);
  append(&head, 4);
  cout << "List: ";
  printList(head);
  cout << "Iterative: " << getCountIterative(head) << "\n";
  cout << "Recursive: " << getCountRecursive(head) << "\n";
}

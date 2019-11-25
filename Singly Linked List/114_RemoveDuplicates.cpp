/**
    Problem: Remove Duplicates in a sorted Linked List

    @author salroid
    www.salroid.me
*/

#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
  int data;
  struct Node *next;
};
 
void removeDuplicates(struct Node *head) {
  Node* currentNode = head;
  Node* nextToNextNode;
 
  if ( currentNode == NULL) {
    return;
  }
  while (currentNode->next != NULL) {
    if (currentNode->data == currentNode->next->data) {
      nextToNextNode = currentNode->next->next;
      free(currentNode->next);
      currentNode->next = nextToNextNode;  
    } else {
       currentNode = currentNode->next;  
    }
  }
}
 
void printList(struct Node *node) {
  while (node != NULL) {
    cout << node->data << "";
    node = node->next;
  }
  cout << "\n";
}
 
void append(struct Node **headRef, int data) {
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  struct Node *last = *headRef;
  newNode->data = data;
  newNode->next = NULL;
  if (*headRef == NULL) {
    *headRef = newNode;
    return;
  }
  while (last->next != NULL) {
    last =  last->next;
  }
  last->next = newNode;
  return;
}
 
int main () {
  struct Node *head = NULL;
  append(&head, 5);
  append(&head, 5);
  append(&head, 6);
  append(&head, 7);
  append(&head, 8);
  append(&head, 8);
  cout << "List: ";
  printList(head);
  removeDuplicates(head);
  cout << "List after removing Duplicates: ";
  printList(head);
  return 0;
}
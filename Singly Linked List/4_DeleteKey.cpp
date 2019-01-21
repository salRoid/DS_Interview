  /**
      Problem: Deleting a node based on the key (first occurence) in Linked List
      @author salroid
      www.salroid.me
  */
   
  #include <bits/stdc++.h>
   
  using namespace std;
   
  struct Node {
    int data;
    struct Node *next;
  };
   
  void printList (struct Node *node) {
    while (node != NULL) {
      cout << node->data << " ";
      node = node->next;
    }
    cout << "\n";
  }
   
  void append (struct Node **headRef, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node *last = *headRef;
    if (*headRef == NULL) {
      *headRef = newNode;
      return;
    }
   
void deleteNode (struct Node **headRef, int key) {
    struct Node *temp = *headRef;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    struct Node *previous = *headRef;
    while (temp != NULL && temp->data != key) {
        previous = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "No Such Key found \n";
    } else {
        previous->next = temp->next;
        free(temp);
    }
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}
   
int main () {
    struct Node *head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    cout << "List: ";
    printList(head);
    deleteNode(&head, 2);
    cout << "List after deletion: ";
    printList(head);
}
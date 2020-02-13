// circular linked list implementation
#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* newNode(int value){
  Node* node = new Node();
  node->data = value;
  node->next = NULL;
  return node;
}

Node* insert(Node* head, int value){
  Node* node = newNode(value);
  if(head==NULL){
    node->next = node;
    return node;
  }
  Node* ptr = head;
  while(ptr->next != head)
    ptr = ptr->next;
  ptr->next = node;
  node->next = head;
  return head;
}

void printList(Node* head){
  if(head == NULL){
    cout << "Empty list" << endl;
    return;
  }
  Node* ptr = head->next;
  cout << head->data << "->";
  while(ptr != head){
    cout << ptr->data << "->";
    ptr = ptr->next;
  }
  cout << "head" << endl;
}

int main(){
  
  Node* list = NULL;
  list = insert(list, 1);
  list = insert(list, 2);
  list = insert(list, 3);
  list = insert(list, 4);
 
  printList(list);

  return 0;
}

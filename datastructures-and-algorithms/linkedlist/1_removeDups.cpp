#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* newNode(int val){
    Node* node = new Node();
    node->data = val;
    node->next = NULL;
    return node;
}


Node* insert(Node* head, int val){
    if(head==NULL) return newNode(val);
    Node* tmp = head;
    while(tmp->next!=NULL) tmp = tmp->next;
    tmp->next = newNode(val);
    return head;
}

void printList(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout << "NULL\n";
}

void removeDuplicates(Node* head){
    Node* ptr = head;
    Node* secondPtr;
    
    while(ptr->next!=NULL){
        secondPtr = ptr;
        while(secondPtr->next!=NULL){
            if(secondPtr->next->data == ptr->data)
                secondPtr->next = secondPtr->next->next;
            else
                secondPtr = secondPtr->next;
        }
        ptr = ptr->next;
    }
}

int main(){
    
    Node* list = NULL;
    
    int entries[] = {1, 1, 5, 2, 6, 7, 5};
    
    for(int i=0; i<sizeof(entries)/sizeof(int); i++)
        list = insert(list, entries[i]);
    
    printList(list);
    
    removeDuplicates(list);
    
    printList(list);
    
    return 0;
}

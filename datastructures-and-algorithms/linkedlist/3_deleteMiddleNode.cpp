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

void deleteMiddleNode(Node* node){
    if(node->next == NULL){
        cout << "Not a middle node" << endl;
        return;
    }
    Node* followNode = node->next;
    node->data = followNode->data;
    node->next = followNode->next;
    free(followNode);
}

int main(){

    Node* list = NULL;
    list = insert(list, 1);
    list = insert(list, 2);
    list = insert(list, 3);
    list = insert(list, 4);
    list = insert(list, 5);
    
    printList(list);

    Node* ptr = list->next->next;
    deleteMiddleNode(ptr);

    printList(list);

    return 0;
}

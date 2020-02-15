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
    Node* ptr = head;
    while(ptr!=head){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "head" << endl;
}

Node* isLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    
    return fast;
}

Node* detectLoop(Node* head){
    Node* loopNode = isLoop(head);
    
    if(loopNode == NULL)
        return loopNode;
    
    Node* ptr1 = head;
    Node* ptr2 = loopNode;
    while(ptr1 != ptr2){
        cout << '1';
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr1;
}

int main(){
    
    Node* list = NULL;
    
    int entries[] = {1, 1, 5, 2, 6, 7, 5};
    
    for(int i=0; i<sizeof(entries)/sizeof(int); i++)
        list = insert(list, entries[i]);
    
    Node* ptr = list;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = list->next->next;
    
    printList(list);
    
    Node* loopNode = detectLoop(list);
    
    if(loopNode == NULL)
        cout << "No loop" << endl;
    else
        cout << "Loop starts at node : " << loopNode->data << endl;
    
    return 0;
}


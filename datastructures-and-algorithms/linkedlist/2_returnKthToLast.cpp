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

Node* findKthFromLast(Node* head, int k){
    // empty list
    if(head==NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;
    int listSize = 0;
    while(fast!=NULL){
        if(listSize >= k)
            slow = slow->next;
        fast = fast->next;
        listSize++;
    }
    
    if(k>listSize)
        return NULL;
    return slow;
}

int main(){

    Node* list = NULL;
    int val = 1;
    while(1){
        cout << "Enter num (-1 to quit): ";
        cin >> val;
        if(val==-1) break;
        list = insert(list, val);
    }
    
    int k;
    cout << "Enter kth node to find from last : ";
    cin >> k;

    printList(list);

    Node* kthNode = findKthFromLast(list, k);

    if(kthNode==NULL)
        cout << "Cant find " << k << "th node from last" << endl;
    else
        cout << k << "th node from last " << kthNode->data << endl;

    return 0;
}


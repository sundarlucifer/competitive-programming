#include <iostream>
#include <unordered_set>
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
    if(head == NULL)
        return node;
    Node* ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = node;
    return head;
}

Node* intersection(Node* list1, Node* list2){
    unordered_set<Node*> list1Addr;
    Node* ptr = list1;
    
    while(ptr!=NULL){
        list1Addr.insert(ptr);
        ptr = ptr->next;
    }
    
    ptr = list2;
    while(ptr != NULL){
        if(list1Addr.find(ptr) != list1Addr.end())
            return ptr;
        ptr = ptr->next;
    }
    
    return NULL;
}

int main(){
    
    Node* list1 = NULL;
    Node* list2 = NULL;
    
    list1 = insert(list1, 1);
    list1 = insert(list1, 2);
    list1 = insert(list1, 3);
    list1 = insert(list1, 4);
    
    list2 = insert(list2, -1);
    list2 = insert(list2, -2);
    list2->next->next = list1->next;
    
    Node* intersectNode = intersection(list1, list2);
    if(intersectNode == NULL)
        cout << "No intersection" << endl;
    else
        cout << "Intersect at " << intersectNode->data << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

const int INF = 1e9;

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

int diff(int num1, int num2){
    return (num1>num2) ? num1-num2 : num2-num1;
}

Node* findNearestMatch(Node* head, int value){
    Node* match = head;
    int bestDifference = diff(head->data, value);
    int currentDifference = INF;
    Node* ptr = head->next;
    while(ptr != NULL){
        currentDifference = diff(ptr->data, value);
        if( currentDifference < bestDifference){
            bestDifference = diff(ptr->data, value);
            match = ptr;
        }
        ptr = ptr->next;
    }
    
    return match;
}

Node* pushFront(Node* head, Node* node){
    node->next = head;
    return node;
}

// no need for return, just to maintatin code consistency
Node* pushNext(Node* head, Node* node){
    node->next = head->next;
    head->next = node;
    return head;
}

Node* partition(Node* head, int partitionValue){
    
    if(head == NULL)
        return head;
    
    Node* partitionNode = findNearestMatch(head, partitionValue);
    cout << "Partition point : " << partitionNode->data << endl;
    
    while(head->data >= partitionNode->data && head!=partitionNode){
        Node* node = head;
        head = head->next;
        partitionNode = pushNext(partitionNode, node);
    }
    Node* ptr = head;
    if(ptr != partitionNode){
        while(ptr->next != partitionNode){
            if(ptr->next->data >= partitionNode->data){
                Node* node = ptr->next;
                ptr->next = ptr->next->next;
                partitionNode = pushNext(partitionNode, node);
            }else{
                ptr = ptr->next;
            }
        }
    }
    ptr = partitionNode;
    while(ptr->next != NULL){
        if(ptr->next->data < partitionNode->data){
            Node* node = ptr->next;
            ptr->next = ptr->next->next;
            head = pushFront(head, node);
        }else{
            ptr = ptr->next;
        }
    }
    return head;
}

int main(){
    
    Node* list = NULL;
    
    int entries[] = {1, 7, 5, 6, 2, 4};
    
    for(int i=0; i<sizeof(entries)/sizeof(int); i++)
        list = insert(list, entries[i]);
    
    printList(list);
    
    list = partition(list, 3);
    
    printList(list);
    
    return 0;
}

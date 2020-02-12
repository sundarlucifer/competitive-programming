// Traverse Linked List from middle to left-right order using recursion
// Refer : https://www.geeksforgeeks.org/traverse-linked-list-from-middle-to-left-right-order-using-recursion/
# include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next=NULL;
    Node(int x) : data(x), next(NULL) {}
};

Node* listMidLeftRight(Node* slow, Node* fast){
    cout << fast<<endl;
    if(!fast){
        cout << slow->data << " ";
        return slow->next;
    }
    else if(fast->next==NULL){
        cout << slow->data << " ";
        return slow->next;
    }else{
        fast = listMidLeftRight(slow->next, fast->next->next);
    }
    cout << slow->data << " ";
    cout << fast->data << " ";
    if(fast->next!=NULL)
        return fast->next;
}

void recursePrint(Node* node){
    if(node){
        cout << node->data << "->";
        recursePrint(node->next);
    }
}

void printList(Node* head){
    recursePrint(head);
    cout << "NULL"<<endl;
}

int main(){
    Node* head;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);

    cout << "Original list : ";
    printList(head);

    listMidLeftRight(head, head);
    
    cout << endl;
    return 0;
}
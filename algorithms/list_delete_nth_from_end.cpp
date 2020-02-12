// Delete Nth element of linked list from end
// Refer : https://www.geeksforgeeks.org/remove-nth-node-from-end-of-the-linked-list/
# include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next=NULL;
    Node(int x) : data(x), next(NULL) {}
};

int recurseDelete(Node* node, int n){
    if(!node){
        return 0;
    }
    int val = recurseDelete(node->next, n);
    if(val == n){       // this is the node in front of nth node from behind
        Node* tmp = node->next;
        node->next=tmp->next;
        free(tmp);
    }
    return val+1;
}

Node* deleteNthFromBehind(Node* head, int n){
    int result = (n>0) ? recurseDelete(head, n) : 0;    // result has the size of list before deleting
    if(result==0 || n>result)
        cout << "List Index Out Of Range"<<endl;
    else if(result==n){
        cout << "Deleting head node...\n";
        Node* tmp = head;
        head=head->next;
        free(tmp);
    }
    return head;
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
    head->next->next->next->next = new Node(5);

    printList(head);

    head=deleteNthFromBehind(head, 5);
    
    printList(head);

    cout << endl;
    return 0;
}
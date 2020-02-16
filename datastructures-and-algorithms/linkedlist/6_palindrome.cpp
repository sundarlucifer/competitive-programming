// O(n) recursive
// but require addtitional flag for now
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

Node* recurseCheckPalindrome(Node*  frontPtr, Node* backPtr, bool* isCompleted){
    if(backPtr == NULL)
        return frontPtr;
    
    frontPtr = recurseCheckPalindrome(frontPtr, backPtr->next, isCompleted);
    if(*isCompleted)
        return frontPtr;
    if(frontPtr->data == backPtr->data){
        if(frontPtr == backPtr || frontPtr->next == backPtr){
            *isCompleted = true;
        }
        return frontPtr->next;
    }else{
        *isCompleted = true;
        return NULL;
    }
}

bool isPalindrome(Node* head){
    bool isCompleted = false;
    Node* middleNode = recurseCheckPalindrome(head, head, &isCompleted);
    if(middleNode == NULL)
        return false;
    else
        return true;
}

int main(){
    
    Node* list = NULL;
    
    int entries[] = {1, 2, 3, 2, 1};
    
    for(int i=0; i<sizeof(entries)/sizeof(int); i++)
        list = insert(list, entries[i]);
    
    if(isPalindrome(list))
        cout << "Yes, it is a plaindrome" << endl;
    else
        cout << "No, not a palindrome" << endl;
    
    return 0;
}


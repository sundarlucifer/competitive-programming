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

Node* reverseLL(Node* head, Node* next, Node* finalHead){
	if(head->next==NULL){
		finalHead = head;
		head->next = next;
		return finalHead;
	}
	finalHead = reverseLL(head->next, head, finalHead);
	head->next = next;
	return finalHead;
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
	
	cout << "Before reversing : ";
	printList(list);

	list = reverseLL(list, NULL, NULL);
	
	cout << "After reversing : ";
	printList(list);

	return 0;
}

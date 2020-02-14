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

Node* reverseLL(Node* head){
	Node* prev = NULL;
	Node* curr = head;
	Node* next = curr;
	while(next!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
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
	
	printList(list);

	list = reverseLL(list);

	printList(list);

	return 0;
}

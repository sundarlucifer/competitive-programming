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

Node* deleteKthFromBehind(Node* head, int k){
	if(head==NULL){
		cout << "Exception : Empty list\n";
		return head;
	}
	Node* slow = head;
	Node* fast = head;
	int count = k+1;
	while(--count){
		if(fast == NULL){
			cout << "Exception : List size lesser than " << k << endl;
			return head;
		}
		fast = fast->next;
	}
	if(fast==NULL) return head->next;
	
	while(fast->next!=NULL){
		count++;
		slow = slow->next;
		fast = fast->next;
	}
	
	slow->next = slow->next->next;
	return head;
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
	cout << "Enter k to delete from behind : ";
	cin >> k;

	printList(list);

	list = deleteKthFromBehind(list, k);

	printList(list);

	return 0;
}

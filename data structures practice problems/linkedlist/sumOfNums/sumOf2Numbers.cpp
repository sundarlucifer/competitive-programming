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

void printList(Node* head){
	Node* tmp = head;
	while(tmp!=NULL){
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << "NULL\n";
}

Node* sumOf2Numbers(Node* list1, Node* list2){
	Node* list3 = NULL;
	Node* ptr1 = list1;
	Node* ptr2 = list2;
	int carry=0, sum;
	while(ptr1!=NULL && ptr2!=NULL){
		cout << "carry : " << carry << endl;
		sum =  (ptr1->data + ptr2->data) % 10;
		list3 = insert(list3, sum + carry);
		carry = (ptr1->data + ptr2->data);
		carry = (carry>9) ? 1 : 0;
	}
	return list3;
}

int main(){

	Node* list1 = NULL;
	Node* list2 = NULL;
	int val = 1;
	//while(1){
	//	cout << "Enter num (-1 to quit): ";
	//	cin >> val;
	//	if(val==-1) break;
	//	list = insert(list, val);
	//}
	
	int num1, num2;
	cin >> num1 >> num2;
	while(num1>0){
		list1 = insert(list1, num1%10);
		num1 /= 10;
	}
	if(list1 == NULL) list1 = insert(list1, 0);
	
	while(num2>0){
		list2 = insert(list2, num2%10);
		num2 /= 10;
	}
	if(list2 == NULL) list2 = insert(list2, 0);
	
	list1 = reverseLL(list1);
	list2 = reverseLL(list2);
	
	printList(list1);
	printList(list2);
	
	Node* sumList = sumOf2Numbers(list1, list2);
	
	printList(sumList);
	
	return 0;
}

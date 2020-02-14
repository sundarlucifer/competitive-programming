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

Node* sumOf2Numbers(Node* list1, Node* list2){
	Node* list3 = NULL;
	Node* ptr1 = list1;
	Node* ptr2 = list2;
	int carry=0, sum;
	while(ptr1!=NULL && ptr2!=NULL){
		sum =  (carry + ptr1->data + ptr2->data);
		list3 = insert(list3, sum%10);
		carry = sum > 9 ? 1 : 0;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
	}
    Node* ptr = (ptr1 == NULL) ? ptr2 : ptr1;
    while(ptr!=NULL){
        sum =  (carry + ptr->data);
        list3 = insert(list3, sum%10);
        carry = sum > 9 ? 1 : 0;
        ptr = ptr->next;
    }
    if(carry > 0)
        list3 = insert(list3, carry);
    
	return list3;
}

int main(){

	Node* list1 = NULL;
	Node* list2 = NULL;
	int val = 1;
	
	int num1, num2;
	cin >> num1 >> num2;
	while(num1>0){
		list1 = insert(list1, num1%10);
		num1 /= 10;
	}
    // if num1 was 0 initially
	if(list1 == NULL) list1 = insert(list1, 0);
	
	while(num2>0){
		list2 = insert(list2, num2%10);
		num2 /= 10;
	}
    // if num2 was 0 initially
	if(list2 == NULL) list2 = insert(list2, 0);
	
    // one's place digit is in head node
    // i.e number is represented in reverse
	printList(list1);
	printList(list2);
	
	Node* sumList = sumOf2Numbers(list1, list2);
	
    // reverse of the sum
	printList(sumList);
	
	return 0;
}

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* myNode = new Node();
    myNode->data = data;
    myNode->left = NULL;
    myNode->right = NULL;
    return myNode;
}

bool isBST(Node* root){
    if(root==NULL)
        return true;
    if(root->left && root->left->data > root->data)
        return false;
    if(root->right && root->right->data < root->data)
        return false;
    return isBST(root->left) && isBST(root->right);
}

int main(){

    Node* tree = newNode(5);
    tree->left = newNode(3);
    tree->left->right = newNode(4);
    tree->right = newNode(8);
    tree->right->right = newNode(10);

    // Convert to non-BST
    tree->right->left = newNode(9);
    

    cout << (isBST(tree) ? "BST" : "Not a BST") << endl;

    return 0;
}
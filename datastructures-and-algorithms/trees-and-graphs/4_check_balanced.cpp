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

Node* bstInsert(Node* root, int data){
    if(root == NULL)
        return newNode(data);
    if(data < root->data){
        if(root->left)
            bstInsert(root->left, data);
        else
            root->left = newNode(data);
    }else if(data > root->data){
        if(root->right)
            bstInsert(root->right, data);
        else
            root->right = newNode(data);
    }
    return root;
}

int height(Node* root){
    // TODO: implement height calc
    if(root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node* root){
    if(root==NULL)
        return true;
    int balanceFactor = height(root->left) - height(root->right);
    printf("Node %2d : height=%d, balance=%d\n", root->data, height(root), balanceFactor);
    bool leftBalanced = isBalanced(root->left);
    bool rightBalanced = isBalanced(root->right);
    return abs(balanceFactor)<2 && leftBalanced && rightBalanced;
}

int main(){

    Node* tree = NULL;
    tree = bstInsert(tree, 5);
    tree = bstInsert(tree, 1);
    tree = bstInsert(tree, 3);
    tree = bstInsert(tree, 8);
    tree = bstInsert(tree, 6);
    tree = bstInsert(tree, 10);
    
    // make unbalanced
    tree = bstInsert(tree, 4);

    cout << (isBalanced(tree) ? "\nBalanced" : "\nNot balanced") << endl;

    return 0;
}
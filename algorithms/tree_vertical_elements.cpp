// Elements of tree, which are on same vertical line
// Interview question
# include <iostream>
# include <map>
# include <vector>
using namespace std;

struct Tree{
    int data;
    Tree* left=NULL;
    Tree* right=NULL;
    Tree(int x) : data(x){}
};

void postorder(Tree* node, int x, map<int,vector<int> > &log){
    if(node){
        log[x].push_back(node->data);
        postorder(node->left, x-1, log);
        postorder(node->right, x+1, log);
    }
}

int main(){
    Tree *tree = new Tree(1);
    tree->left = new Tree(2);
    tree->right = new Tree(3);
    tree->left->left = new Tree(4);
    tree->left->right = new Tree(5);
    tree->right->left = new Tree(6);
    tree->right->right = new Tree(7);

    map<int,vector<int> > log;

    postorder(tree, 0, log);
    for(map<int,vector<int> >::iterator ptr=log.begin();ptr!=log.end();ptr++){
        cout << ptr->first << " : ";
        for(vector<int>::iterator itr=ptr->second.begin();itr!=ptr->second.end();itr++)
            cout << *itr << "->";
        cout << "NULL" << endl;
    }

    cout << endl;
    return 0;
}
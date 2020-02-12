# include <iostream>
# include <map>
using namespace std;

struct Node {
  int data;
  Node* left = NULL;
  Node* right = NULL;
  Node(int x) : data(x) {}
};

void findLeftView(Node* node, int level, map<int, int> &view){
  if(node!=NULL){
    if(view.find(level) == view.end())
      view[level] = node->data;
    findLeftView(node->left, level+1, view);
    findLeftView(node->right, level+1, view);
  }
}

int main(){
  Node *tree = new Node(1);
  tree->left = new Node(2);
  tree->right = new Node(3);
  tree->left->right = new Node(4);
  tree->right->left = new Node(5);
  tree->right->right = new Node(6);
  tree->right->left->right = new Node(7);

  map<int, int> leftView;
  findLeftView(tree, 0, leftView);

  for(auto entry : leftView){
    cout << entry.first << " : " << entry.second << endl;
  }

  return 0;
}

    //  __1__
    // |     |
    // 2_   _3_
    //  |  |   |
    //  4  5_  6
    //       |
    //       7

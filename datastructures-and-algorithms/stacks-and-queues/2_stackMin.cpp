// O(1) time in O(1) space
#include <iostream>
#include <stack>
using namespace std;

class MinStack{
    stack<int> _stack;
    int minElement;
public:
    
    // O(1)
    void min(){
        if(_stack.empty())
            cout << "Empty stack" << endl;
        else
            cout << "Min : " << minElement;
    }
    
    // O(1)
    void top(){
        if(_stack.empty()){
            cout << "Empty stack" << endl;
            return;
        }
        
        int topElement = _stack.top();
        if(topElement < minElement)
            topElement = minElement;
        
        cout << "Top : " << topElement;
    }
    
    // O(1)
    void push(int value){
        if(_stack.empty()){
            minElement = value;
        }else if(value < minElement){
            int temp = 2*value - minElement;
            minElement = value;
            value = temp;
        }
        
        cout << "Push : " << value << endl;
        _stack.push(value);
    }
    
    // O(1)
    void pop(){
        if(_stack.empty())
            cout << "Empty stack" << endl;
        
        int topElement = _stack.top();
        if(topElement < minElement)
            minElement = 2*minElement - topElement;
        
        _stack.pop();
    }
};

int main(){
    
    MinStack myMinStack = MinStack();
    
    int entries[] = {5, 2, 7, 3, 1};
    int entrySize = sizeof(entries)/sizeof(int);
    
    for(int i=0; i<entrySize; i++)
        myMinStack.push(entries[i]);
    
    for(int i=0; i<entrySize; i++){
        myMinStack.top();
        cout << " ";
        myMinStack.min();
        cout << endl;
        myMinStack.pop();
    }
    
    return 0;
}

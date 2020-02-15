#include <iostream>
#include <stack>
using namespace std;

class QueueViaStack{
  
    stack<int> _primaryStack;
    stack<int> _secondryStack;
    
public:
    void enqueue(int value){
        _primaryStack.push(value);
    }
    
    void dequeue(){
        if(_secondryStack.empty()){
            while(!_primaryStack.empty()){
                _secondryStack.push( _primaryStack.top() );
                _primaryStack.pop();
            }
        }
        if(!_secondryStack.empty()){
            cout << "Dequeue : " << _secondryStack.top() << endl;;
            _secondryStack.pop();
        }
        // else queue is empty
    }
    
    bool empty(){
        return _primaryStack.empty() && _secondryStack.empty();
    }
    
    void clear(){
        cout << "\nClearing queue : " << endl;
        while(!empty())
            dequeue();
    }
    
};

int main(){
        
    QueueViaStack myQueue = QueueViaStack();
    
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.dequeue();
    myQueue.enqueue(4);
    myQueue.dequeue();
    
    myQueue.clear();
    
    return 0;
}

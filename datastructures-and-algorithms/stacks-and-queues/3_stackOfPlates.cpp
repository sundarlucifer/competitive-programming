#include <iostream>
#include <list>
using namespace std;

class Stack{
    int STACK_SIZE;
    int* _stack;
    int _top;
public:
    Stack(int stackSize){
        STACK_SIZE = stackSize;
        _top = -1;
        _stack = (int*) malloc(STACK_SIZE * sizeof(int));
    }

    bool empty(){
        return _top < 0 ? true : false;
    }
    
    bool full(){
        return _top+1 >= STACK_SIZE;
    }

    bool push(int value){
        if(full())
            return false;
        _top++;
        _stack[_top] = value;
        return true;
    }
    
    bool pop(){
        if(empty())
            return false;
        _top--;
        return true;
    }
    
    int top(){
        if(empty())
            return -1;
        return _stack[_top];
    }
    
};

class SetOfStacks{
    int STACK_SIZE;
    list<Stack> _stackList;
    
    void addStack(){
        _stackList.push_front( Stack(STACK_SIZE) );
//        cout << "SetOfStacks : adding new stack" << endl;
    }
    
    void removeStack(){
        _stackList.pop_front();
    }
public:
    SetOfStacks(int stackSize){
        STACK_SIZE = stackSize;
        addStack();
    }
    
    void push(int value){
        if(_stackList.front().full())
            addStack();
        _stackList.front().push(value);
    }
    
    void pop(){
        if(_stackList.front().empty()){
            cout << "Stack Underflow" << endl;
        }else{
            _stackList.front().pop();
            if(_stackList.front().empty())
                removeStack();
            if(_stackList.empty())
                addStack();
        }
    }

    int top(){
        return _stackList.front().top();
    }
    
};

int main(){
    SetOfStacks mySetOfStacks = SetOfStacks(3);
    
    int entries[] = {1, 2, 3, 4, 5, 6, 7};
    int entrySize = sizeof(entries)/sizeof(int);
    
    for(int i=0; i<entrySize; i++)
        mySetOfStacks.push(entries[i]);
    
    for(int i=0; i<entrySize; i++){
        cout << mySetOfStacks.top() << endl;
        mySetOfStacks.pop();
    }
    
    return 0;
}


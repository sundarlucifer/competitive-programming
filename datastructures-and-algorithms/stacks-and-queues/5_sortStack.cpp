// incomplete
#include <iostream>
using namespace std;

class Stack{
    static const int STACK_SIZE = 10;
    int _stack[STACK_SIZE];
    int top = -1;
public:

    bool isEmpty(){
        return top < 0 ? true : false;
    }

    void push(int value){
        if(top+1 >= STACK_SIZE){
            cout << "Stack overflow" << endl;
        }else{
            top++;
            _stack[top] = value;
        }
    }
    
    int pop(){
        if(isEmpty()){
            cout << "Stack underflow" << endl;
        }else{
            int value = peek();
            top--;
            return value;
        }
    }
    
    int peek(){
        int value = -1;
        if(isEmpty()){
            cout << "Top on empty stack, returning -1" << endl;
        }else{
            value = _stack[top];
        }
        return value;
    }
    
    int size(){
        return top + 1;
    }
    
    void sort(){
        if(size() <= 1)
            return;
        
        Stack tempStack = Stack();
        int tempTop = top;
        int value;
        while(!isEmpty()){
            value = pop();
            while(tempStack.peek()<value && !tempStack.isEmpty()){
                push( tempStack.pop() );
            }
            tempStack.push(value);
            while(top >= tempTop){
                tempStack.push( pop() );
            }
        }
    }
};

int main()
{
    Stack myStack = Stack();
    
    myStack.push(2);
    myStack.push(4);
    myStack.push(3);
    myStack.push(1);
    
    myStack.sort();
    
    cout << "Stack elements : " << endl;
    while(!myStack.isEmpty()){
        cout << myStack.pop() << endl;
    }

    return 0;
}

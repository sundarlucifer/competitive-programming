#include <iostream>
using namespace std;

class Stack{
    static const int STACK_SIZE = 10;
    int _stack[STACK_SIZE];
    int top;
public:
    
    Stack(){
        top = -1;
    }

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
            return -1;
        }
        int value = peek();
        top--;
        return value;
    }
    
    int peek(){
        int value = -1;
        if(isEmpty()){
            cout << "Peek on empty stack, returning -1" << endl;
        }else{
            value = _stack[top];
        }
        return value;
    }
    
    int size(){
        return top + 1;
    }
    
    void sort(){
        // 0 or 1 element -> already sorted
        if(size() <= 1)
            return;
        
        Stack tempStack = Stack();
        int tempTop;
        int value;
        
        tempStack.push( pop() );
        
        while(!isEmpty()){
            tempTop = top;
            value = pop();
            while(tempStack.peek()>value && !tempStack.isEmpty()){
                push( tempStack.pop() );
            }
            tempStack.push(value);
            while(top >= tempTop){
                tempStack.push( pop() );
            }
        }
        while(!tempStack.isEmpty()){
            push(tempStack.pop());
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

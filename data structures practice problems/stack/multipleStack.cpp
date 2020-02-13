#include <iostream>
using namespace std;

class MultiStack{
private:
	int STACK_SIZE;
	int STACK_COUNT;
	int* topOfStack;
	int* _stack;
	
public:
	MultiStack(int stackSize, int stackCount){
		STACK_SIZE = stackSize;
		STACK_COUNT = stackCount;
		topOfStack = (int*)malloc(STACK_SIZE*STACK_COUNT);
		_stack = (int*)malloc(STACK_SIZE*STACK_COUNT*sizeof(int));
	}
	void push(int stackIndex, int value){
		stackIndex--; // index starts at 0
		if(topOfStack[stackIndex]+1 > STACK_SIZE)
			cout << "Stack Overflow @ Stack-" << stackIndex << endl;
		else
			_stack[++topOfStack[stackIndex]] = value;
	}
	
	int pop(int stackIndex){
		stackIndex--; // index starts at 0
		if(topOfStack[stackIndex]-1 < 0)
			cout << "Stack Underflow @ Stack-" << stackIndex << endl;
		else
			return _stack[--topOfStack[stackIndex]];
	}

	int top(int stackIndex){
		stackIndex--; // index starts at 0
		if(topOfStack[stackIndex] < 0)
			cout << "Stack Empty @ Stack-" << stackIndex << endl;
		else
			return _stack[topOfStack[stackIndex]];
	}
	
};

int main(){
	MultiStack multiStack = MultiStack(2, 3);
	multiStack.push(1, 1);
	cout << multiStack.top(1) << endl;
	multiStack.push(1, 2);
	cout << multiStack.top(1) << endl;
	multiStack.push(1, 3);
	cout << multiStack.top(1) << endl;
	multiStack.pop(1);
	cout << multiStack.top(1) << endl;
	multiStack.pop(1);
	cout << multiStack.top(1) << endl;
	multiStack.pop(1);
	cout << multiStack.top(1) << endl;
	return 0;
}

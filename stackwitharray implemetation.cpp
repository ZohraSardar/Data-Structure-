#include <iostream>
using namespace std;

class Stack {
private:
    int topIndex; // index of the top element in the stack
    int size; // size of the stack
    int* arr; // array to hold the elements of the stack
    
public:
    Stack(int s = 10) { // constructor to initialize the stack with size s (default size 10)
        size = s;
        arr = new int[size];
        topIndex = -1;
    }
    
    ~Stack() { // destructor to free the memory allocated for the stack array
        delete[] arr;
    }
    
    void push(int element) { // adds a new element to the top of the stack
        if (topIndex == size - 1) { // stack is full
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = element; // increment topIndex and insert the new element at the top
    }
    
    int top() { // returns the top element of the stack
        if (topIndex == -1) { // stack is empty
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[topIndex]; // return the element at the top of the stack
    }
    
    int pop() { // removes the top element of the stack
        if (topIndex == -1) { // stack is empty
            cout << "Stack Underflow" << endl;

        }
        cout<<"Pop element is "<<arr[topIndex]<<endl;
        topIndex--; // decrement topIndex to remove the top element
//        return arr[topIndex];
//    	;
	}
};

int main() {
    Stack s(10); // create a stack of size 10
    s.push(1);
    s.push(2);
    s.push(3);
	cout<<"top is"<<s.top()<<endl;
    s.pop();
	s.pop();
	s.pop(); // should print "Stack Underflow"
//    return 0;
}

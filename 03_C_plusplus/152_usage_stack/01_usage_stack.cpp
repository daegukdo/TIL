/*
@ LeetCode

Stack - Usage

Most popular languages provide built-in stack library so you don't have to reinvent the wheel. 
Besides initialization, we need to know how to use the two most important operations, pop and push. 
Also, you should be able to get the top element from the stack. 
Below are some code examples for your reference:

ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1358/
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    // 1. Initialize a stack.
    stack<int> s;
    
    // 2. Push new element.
    // push 4 elements
    s.push(5);
    s.push(13);
    s.push(8);
    s.push(6);
    
    // 3. Check if stack is empty.
    // pass this if statement
    if (s.empty()) {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    
    // 4. Pop an element.
    // pop '6' in stack (last in)
    s.pop();
    
    // 5. Get the top element.
    // top element is '8'
    cout << "The top element is: " << s.top() << endl;
    
    // 6. Get the size of the stack.
    // size is 3
    cout << "The size is: " << s.size() << endl;
}

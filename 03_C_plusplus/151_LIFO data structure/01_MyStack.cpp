/*
@ LeetCode

Last-in-first-out Data Structure

In a LIFO data structure, the newest element added to the queue will be processed first.

Different from the queue, the stack is a LIFO data structure. 
Typically, the insert operation is called push in a stack. 
Similar to the queue, a new element is always added at the end of the stack. 
However, the delete operation, pop, will always remove the last element which is opposite from the queue.

Implementation - Stack

The implementation of a Stack is easier than a Queue. 
A dynamic array is sufficient to implement a stack structure. 
Here we provide a simple implementation for your reference: (below)

ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1369/
*/

#include <iostream>
#include <vector>

using namespace std;

class MyStack {
    private:
        vector<int> data;               // store elements
    public:
        /** Insert an element into the stack. */
        void push(int x) {
            data.push_back(x);
        }
        /** Checks whether the queue is empty or not. */
        bool isEmpty() {
            return data.empty();
        }
        /** Get the top item from the queue. */
        int top() {
            return data.back();
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool pop() {
            if (isEmpty()) {
                return false;
            }
            data.pop_back();
            return true;
        }
};

int main() {
    // define MyStack and add 1, 2, 3
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    for (int i = 0; i < 4; ++i) {
        // if statement do not operate 4th as i is 4
        if (!s.isEmpty()) {
            // show '3' -> '2' -> '1'
            cout << s.top() << endl;
        }
        // show 'true' -> 'true' -> 'true' -> 'false'
        cout << (s.pop() ? "true" : "false") << endl;
    }
}

/*
@ LeetCode - Implement Stack using Queues

Implement a last in first out (LIFO) stack using only two queues. 

The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, the queue may not be supported natively. 

You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.


Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.

Follow-up: Can you implement the stack using only one queue?

ref : https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1387/
*/

#include <iostream>  
#include <vector>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int>* queueIn;
    queue<int>* queueTmp;

public:
    /** Initialize your data structure here. */
    MyStack() {
        queueIn = new queue<int>();
        queueTmp = new queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        queueIn->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int rstVal = 0;

        while (!(queueIn->empty())) {
            if (queueIn->size() == 1) {
                rstVal = queueIn->front();
                queueIn->pop();
            }
            else {
                queueTmp->push(queueIn->front());
                queueIn->pop();
            }
        }

        while (!(queueTmp->empty())) {
            queueIn->push(queueTmp->front());
            queueTmp->pop();
        }

        return rstVal;
    }

    /** Get the top element. */
    int top() {
        int rstVal = 0;

        while (!(queueIn->empty())) {
            if (queueIn->size() == 1) {
                rstVal = queueIn->front();
            }

            queueTmp->push(queueIn->front());
            queueIn->pop();
        }

        while (!(queueTmp->empty())) {
            queueIn->push(queueTmp->front());
            queueTmp->pop();
        }

        return rstVal;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queueIn->empty();
    }
};

int main() {
    queue<int> queueIn;

    queueIn.push(1);
    queueIn.push(2);

    int b = queueIn.front();

    queueIn.pop();

    int a = queueIn.size();

    return 0;
}

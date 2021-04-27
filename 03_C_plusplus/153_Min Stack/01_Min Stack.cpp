/*
@ LeetCode - Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 
Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

Consider each node in the stack having a minimum value. (Credits to @aakarshmadhavan)

ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1360/
ref : https://stackoverflow.com/questions/13015932/how-to-find-minimum-value-from-vector/13015988
*/

#include <iostream>  
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
private:
	vector<int> vct;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
		vct.push_back(val);
    }
    
    void pop() {
		vct.pop_back();
    }
    
    int top() {
        return vct[vct.size() - 1];
    }
    
    int getMin() {
        return *min_element( begin(vct), end(vct) );
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {

    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    int i1 = minStack->getMin(); // return -3
    minStack->pop();
    int i2 = minStack->top();    // return 0
    int i3 = minStack->getMin(); // return -2

    return 0;
}
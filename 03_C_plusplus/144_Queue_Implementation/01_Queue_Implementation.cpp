/* 
@ LeetCode
1. First-in-first-out Data Structure

In a FIFO data structure, the first element added to the queue will be processed first.

As shown in the picture above, the queue is a typical FIFO data stucture. 

The insert operation is also called enqueue and the new element is always added at the end of the queue. 

The delete operation is called dequeue. You are only allowed to remove the first element.

ref : https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1355/

2. Queue - Implementation

To implement a queue, we may use a dynamic array and an index pointing to the head of the queue.

As mentioned, a queue should support two operations: enqueue and dequeue. 

Enqueue appends a new element to the queue while dequeue removes the first element. 

So we need an index to indicate the starting point.

Here is an implementation for your reference:

ref : https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1366/

3. Circular Queue

Previously, we have provided a straightforward but inefficient implementation of queue.

A more efficient way is to use a circular queue. 

Specifically, we may use a fixed-size array and two pointers to indicate the starting position and the ending position. 

And the goal is to reuse the wasted storage we mentioned previously.

Let's take a look at an example to see how a circular queue works. 

You should pay attention to the strategy we use to enqueue or dequeue an element.

Review the animation carefully to figure out the strategy we use to check if a queue is empty or full.

For the next exercise, we will let you try to implement the circular queue by yourself and provide a solution later.

ref : https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1396/
*/

#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
    private:
        // store elements
        vector<int> data;       
        // a pointer to indicate the start position
        int p_start;            
    public:
        MyQueue() {p_start = 0;}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            p_start++;
            return true;
        };
        /** Get the front item from the queue. */
        int Front() {
            return data[p_start];
        };
        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return p_start >= data.size();
        }
};

int main() {
	// q ... 7; 5; 3
    MyQueue q;
    q.enQueue(7);
    q.enQueue(5);
    q.enQueue(3);

	// show 7
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }

	// q ... 5; 3
    q.deQueue();

	// show 5
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }

	// q ... 3
    q.deQueue();
	
	// show 3
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }

	return 0;
}

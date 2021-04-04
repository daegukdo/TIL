/*
@ LeetCode

Queue - Usage

Most popular languages provide built-in Queue library so you don't have to reinvent the wheel.

As mentioned before, the queue has two important operations, enqueue and dequeue. 

Besides, we should be able to get the first element in a queue since the first element should be processed first.

Below are some examples of using the built-in Queue library and its common operations.

We provide exercise after this article to help you familiarize with these operations. 

And remember when you want to process the elements in order, using a queue might be a good choice.

ref : https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1367/
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 1. Initialize a queue.
    queue<int> q;

    // 2. Push new element.
    q.push(5);
    q.push(13);
    q.push(8);
    q.push(6);

    // 3. Check if queue is empty.
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
        return 0;
    }

    // 4. Pop an element.
    q.pop();

    // 5. Get the first element.
    cout << "The first element is: " << q.front() << endl;

    // 6. Get the last element.
    cout << "The last element is: " << q.back() << endl;

    // 7. Get the size of the queue.
    cout << "The size is: " << q.size() << endl;

	return 0;
}
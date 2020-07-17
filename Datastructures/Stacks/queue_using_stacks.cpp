// Implementation of queues using stack
// SlothyCoder16
// July 17, 2020

class MyQueue {
public:
    /** Initialize your data structure here. */
    int numElements;
    int stack[1000000];

    MyQueue() {
        this->numElements = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        this->stack[this->numElements] = x;
        this->numElements = this->numElements + 1;

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = this->stack[0];
        for(int i=1; i<numElements; i++)
            this->stack[i-1] = this->stack[i];
        this->numElements = this->numElements - 1;
        return res;

    }

    /** Get the front element. */
    int peek() {
        return this->stack[0];
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(this->numElements == 0) {
            return true;
        }

        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

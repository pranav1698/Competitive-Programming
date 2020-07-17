// Implementation of Stack to get minimum minElement
// SlothyCoder16
// July 17, 2020

class MinStack {
public:
    /** initialize your data structure here. */
    int numElements;
    int stack[1000000];

    MinStack() {
        this->numElements = 0;
    }

    void push(int x) {
        this->stack[this->numElements] = x;
        this->numElements = this->numElements + 1;
    }

    void pop() {
        int res = this->stack[(this->numElements) - 1];
        this->stack[(this->numElements) - 1] = 0;
        this->numElements = this->numElements - 1;
    }

    int top() {
        int res = this->stack[(this->numElements) - 1];
        return res;

    }

    int getMin() {
        int minElement = INT_MAX;
        if(this->numElements <= 0)
            return -1;

        for(int i=0; i<(this->numElements); i++)
            minElement = min(minElement, this->stack[i]);
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

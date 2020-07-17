// Implementation of baseball game using stack
// SlothyCoder16
// July 17, 2020


class MyStack {
public:
    int numElements;
    int stack[1000000];

    MyStack() {
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
        return this->stack[(this->numElements) - 1];
    }

    int getFirstTwo() {
        if(numElements <= 1)
            return -1;

       return this->stack[(this->numElements) - 1] + this->stack[(this->numElements) - 2];
    }

    int sum() {
        unsigned long long int sum = 0;
        for(int i=0; i<this->numElements; i++)
            sum = sum + this->stack[i];

        return sum;
    }
};

class Solution {
public:
    int calPoints(vector<string>& ops) {
        MyStack* obj = new MyStack();

        for(int i=0; i<ops.size(); i++){
            if(ops[i] == "+") {
                obj->push(obj->getFirstTwo());
            } else if(ops[i] == "D") {
                obj->push(2 * obj->top());
            } else if(ops[i] == "C") {
                obj->pop();
            } else {
                int x=0;
                 stringstream geek(ops[i]);
                geek >> x;
                obj->push(x);
            }
        }

        return obj->sum();
    }
};

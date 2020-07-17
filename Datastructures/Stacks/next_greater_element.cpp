// Next Greater Element using stack
// SlothyCoder16
// July 17, 2020


class MyStack {
public :
    int numElements;
    int stack[1000000];

    MyStack() {
        this->numElements = 0;
    }

    int top() {
        return this->stack[this->numElements - 1];
    }

    void push(int x) {
        this->stack[this->numElements] = x;
        this->numElements = this->numElements + 1;
    }

    int findIndex(int x) {
        for(int i=0; i<numElements; i++)
            if(this->stack[i] == x)
                return i;
        return -1;
    }

    int getNextMax(int x) {
        int index = findIndex(x);
        if(index == -1)
            return -1;

        for(int i=index+1; i<this->numElements; i++){
            if(this->stack[i] > x){
                return this->stack[i];
            }
        }

        return -1;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        MyStack* obj = new MyStack();

        for(int i=0; i<nums2.size(); i++)
            obj->push(nums2[i]);

        for(int i=0; i<nums1.size(); i++)
            res.push_back(obj->getNextMax(nums1[i]));

        return res;
    }
};

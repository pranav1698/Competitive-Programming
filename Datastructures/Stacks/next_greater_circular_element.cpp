// Next greater element in circular array
// SlothyCoder16
// July 17, 2020


class MyStack {
public :
    int numElements;
    int stack[1000000];

    MyStack() {
        this->numElements = 0;
    }

    void push(int x) {
        this->stack[this->numElements] = x;
        this->numElements = this->numElements + 1;
    }

    int getNextMax(int index) {
        int i = index + 1;
        if(i == this->numElements)
            i = 0;

        while(i!=index){
            if(this->stack[i] > this->stack[index]) {
                return this->stack[i];
            }
            i = (i + 1) % this->numElements;
        }

        return -1;
    }
};



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        MyStack* obj = new MyStack();

        for(int i=0; i<nums.size(); i++)
            obj->push(nums[i]);

        for(int i=0; i<nums.size(); i++){
            res.push_back(obj->getNextMax(i));
        }



        return res;
    }
};

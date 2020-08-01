// Finding kth largest element in the stream
// SlothyCoder16
// August 01, 2020

class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++)
            this->pq.push(nums[i]);
    }

    int add(int val) {
        this->pq.push(val);
        priority_queue<int> temp = this->pq;
        int i = 0;
        int res;
        while(i != this->k) {
            res = temp.top();
            temp.pop();
            i++;
        }
        return res;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

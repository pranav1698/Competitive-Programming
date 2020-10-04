// Sliding Window Maximum
// SlothyCoder16
// October 05, 2020

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for(int i=0; i<k; i++) q.push({nums[i], i});

        for(int i=k; i<nums.size(); i++) {
            res.push_back(q.top().first);
            while(!q.empty() && q.top().second<=(i-k)) {
                q.pop();
            }
            q.push({nums[i], i});
        }

        res.push_back(q.top().first);
        return res;
    }
};

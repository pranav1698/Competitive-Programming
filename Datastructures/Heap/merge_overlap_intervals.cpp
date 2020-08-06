// Merging overlap intervals using Min Heap
// SlothyCoder16
// August 06, 2020

class compare {
public:
    bool operator()(vector<int> a, vector<int> b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;

        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(int i=0; i<intervals.size(); i++)
            pq.push(intervals[i]);

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            vector<int> next = pq.top();
            pq.pop();

            if(curr[1] >= next[0]){
                if(pq.size() != 0) {
                    pq.push({curr[0], max(curr[1], next[1])});
                } else {
                    res.push_back({curr[0], max(curr[1], next[1])});
                }
            } else {
                res.push_back(curr);
                if(pq.size() != 0) {
                    pq.push(next);
                } else {
                    res.push_back(next);
                }
            }
        }

        return res;
    }
};

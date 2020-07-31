// K pairs with smallest sum
// SlothyCoder16
// August 1, 2020

class compare {
public:
    bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
        return (p1.first + p1.second) > (p2.first + p2.second);
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                pair<int, int> p;
                p.first = nums1[i];
                p.second = nums2[j];
                pq.push(p);
            }
        }

        int i=0;
        while(i != k && !pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            res.push_back({p.first, p.second});
            i++;
        }

        return res;

    }
};

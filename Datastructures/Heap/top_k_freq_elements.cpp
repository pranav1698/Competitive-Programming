// Top K frequent elements in array
// SlothyCoder16
// August 1, 2020

class compare {
public:
    bool operator()(const pair<int,int> p1, const pair<int, int> p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = m[nums[i]] + 1;


        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        map<int, int>::iterator it = m.begin();
        while(it != m.end()) {
            pair<int, int> p;
            p.first = it->first;
            p.second = it->second;
            pq.push(p);
            it++;
        }

        int i=0;
        while(i != k && !pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            res.push_back(p.first);
            i++;
        }


        return res;
    }
};

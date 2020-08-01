// Finding last stone weight using the following pattern
// SlothyCoder16
// August 01, 2020

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++)
            pq.push(stones[i]);

        while(pq.size() != 1 && !pq.empty()) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a != b) {
                pq.push(abs(a-b));
            }
        }

        if(pq.size() == 1)
            return pq.top();

        return 0;
    }
};

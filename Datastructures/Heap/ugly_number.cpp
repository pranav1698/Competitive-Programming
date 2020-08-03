// Finding nth ugly number using min heap
// SlothyCoder16
// August 03, 2020

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0) return -1;

        unsigned long long int curr;
        priority_queue<unsigned long long int, vector<unsigned long long int>, greater<unsigned long long int>> pq;
        unordered_map<unsigned long long int, unsigned long long int> umap;
        umap[1] = 1;
        pq.push(1);

        int i=0;
        while(i != n && !pq.empty()) {
            curr = pq.top();
            pq.pop();

            if(umap[2*curr] == 0)
                pq.push(2*curr);
            umap[2*curr] = umap[2*curr] + 1;
            if(umap[3*curr] == 0)
                pq.push(3*curr);
            umap[3*curr] = umap[3*curr] + 1;
            if(umap[5*curr] == 0)
                pq.push(5*curr);
            umap[5*curr] = umap[5*curr] + 1;

            i++;
        }

        return curr;
    }
};

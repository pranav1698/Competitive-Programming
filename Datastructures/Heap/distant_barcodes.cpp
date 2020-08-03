// Finding distant barcodes using max heap
// SlothyCoder16
// August 04, 2020


class compare {
public:
    bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
        return p1.second < p2.second;
    }
};


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> res;
        unordered_map<int, int> umap;
        for(int i=0; i<barcodes.size(); i++)
            umap[barcodes[i]] = umap[barcodes[i]] + 1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int>::iterator it = umap.begin();
        while(it != umap.end()) {
            pq.push({it->first, it->second});
            it++;
        }

        while(pq.size() > 1) {
            int curr = pq.top().first;
            pq.pop();
            int next = pq.top().first;
            pq.pop();
            res.push_back(curr);
            res.push_back(next);
            umap[curr] = umap[curr] -1;
            umap[next] = umap[next] - 1;

            if(umap[curr] > 0)
                pq.push({curr, umap[curr]});
            if(umap[next] > 0)
                pq.push({next, umap[next]});
        }

        if(!pq.empty()) {
            int last = pq.top().first;
            pq.pop();
            if(umap[last] > 1)
                return res;

            res.push_back(last);
        }


        return res;
    }
};

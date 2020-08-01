// Finding k most frequent words
// SlothyCoder16
// August 01, 2020

class compare {
public:
    bool operator()(const pair<string, int> p, const pair<string, int> q) {
        if(p.second != q.second) {
            return p.second < q.second;
        }

        return p.first > q.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> umap;
        for(int i=0; i<words.size(); i++)
            umap[words[i]] = umap[words[i]] + 1;

        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
        unordered_map<string, int>::iterator it = umap.begin();
        while(it != umap.end()) {
            pq.push({it->first, it->second});
            it++;
        }

        int i=0;
        while(i != k && !pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
            i++;
        }

        return res;
    }
};

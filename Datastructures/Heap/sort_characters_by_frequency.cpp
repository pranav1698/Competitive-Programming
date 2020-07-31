// Sorting characters by frequency
// SlothyCoder16
// August 1, 2020

class compare {
public:
    bool operator()(const pair<char, int> p1, const pair<char, int> p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        string res="";
        unordered_map<char, int> umap;
        for(int i=0; i<s.length(); i++)
            umap[s[i]]++;


        priority_queue<pair<int, char>> pq;
        unordered_map<char, int>::iterator it = umap.begin();
        for(auto it=umap.begin();it!=umap.end();it++){
            pq.push({it->second,it->first});
        }

        while(pq.size() > 0) {
            char c = pq.top().second;
            int freq = pq.top().first;
            for(int i=1;i<=freq;i++){
                res.push_back(c);
            }
            pq.pop();
        }

        return res;
    }
};

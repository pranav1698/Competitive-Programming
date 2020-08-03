// Reorganiza a string using max Heap
// SlothyCoder16
// August 04, 2020

class compare {
public:
    bool operator()(const pair<char, int> p1, const pair<char, int> p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> umap;
        for(int i=0; i<S.length(); i++)
            umap[S[i]] = umap[S[i]] + 1;

        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        unordered_map<char, int>::iterator it = umap.begin();
        while(it != umap.end()) {
            pq.push({it->first, it->second});
            it++;
        }


        string res = "";
        while(pq.size() > 1) {
            char current = pq.top().first;
            pq.pop();
            char next = pq.top().first;
            pq.pop();
            res = res + current + next;
            umap[current] = umap[current] -1;
            umap[next] = umap[next] -1;

            if(umap[current] > 0)
                pq.push({current, umap[current]});
            if(umap[next] > 0)
                pq.push({next, umap[next]});

        }

        if(!pq.empty()) {
            char last = pq.top().first;
            if(umap[last] > 1) {
                return "";
            } else {
                res = res + last;
            }
        }



        return res;
    }
};

// Making list of points sorted from distance from given points
// SlothyCoder16
// August 06, 2020

class compare {
public:
    bool operator()(const pair<vector<int>, int> p1, const pair<vector<int>, int> p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, compare> pq;
        vector<vector<int>> res;

        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                vector<int> coord;
                coord.push_back(i);
                coord.push_back(j);
                int distance = abs(r0 - i) + abs(c0 - j);
                pq.push({coord, distance});
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};

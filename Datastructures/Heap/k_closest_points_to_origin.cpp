// Finding K closest points to the origin 
// SlothyCoder16
// August 01, 2020

class compare {
public:
    bool operator()(const pair<vector<int>, double> a, const pair<vector<int>, double> b){
        return a.second > b.second;
    }
};

class Solution {
public:
    double findDistance(vector<int> num) {
        double sum = pow(num[0], 2) + pow(num[1], 2);
        return sqrt(sum);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>, compare> pq;
        for(int i=0; i<points.size(); i++)
            pq.push({points[i], findDistance(points[i])});

        int i=0;
        while(i != K && !pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
            i++;
        }
        return res;
    }
};

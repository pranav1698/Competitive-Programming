// Finding k closest points to origin
// SlothyCoder16
// August 10, 2020

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(), points.begin(), [](const vector<int> p1, const vector<int> p2) {
            double d1 = sqrt(pow(p1[0], 2) + pow(p1[1], 2));
            double d2 = sqrt(pow(p2[0], 2) + pow(p2[1], 2));
            return d1 < d2;
        });

        int i=0;
        while(i!=K) {
            res.push_back(points[i]);
            i++;
        }
        return res;
    }
};

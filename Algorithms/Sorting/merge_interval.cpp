// Merge Intervals using sorting
// SlothyCoder16
// August 06, 2020

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;

        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &f, const vector<int> &s) {
            return f[0] < s[0];
        });

        int n = intervals.size();
        int start = intervals[0][0],end = intervals[0][1];
        for (int i = 1;i<n;i++) {
            vector<int>& s = intervals[i];
            if (end>=s[0]) {
                end = max(end,s[1]);
            }
            else {
                res.push_back(vector<int> {start,end});
                start = s[0];
                end = s[1];
            }
        }
        res.push_back(vector<int> {start,end});

        return res;
    }
};

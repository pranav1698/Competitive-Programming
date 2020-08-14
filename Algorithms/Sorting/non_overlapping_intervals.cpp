// Find minimum number of intervals to remove, to get non-overlapping intervals
// SlothyCoder16
// August 15, 2020

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int> i1, const vector<int> i2){
            return i1[1] < i2[1];
        });

        int start = intervals[0][0];
        int end  = intervals[0][1];
        int res = intervals.size()-1;
        for(int i=1; i<intervals.size(); i++) {
            if(end <= intervals[i][0]) {
                res--;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }


        return res;
    }
};

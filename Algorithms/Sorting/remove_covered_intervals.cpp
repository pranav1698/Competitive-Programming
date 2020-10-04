// Remove Covered Intervals
// SlothyCoder16
// October 04, 2020

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b) {
           return a[0]<b[0];
        });

        int count=0;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            vector<int> f=intervals[i];
            if(end>f[0]) {
                if(end<f[1] && start<f[0]) {
                    count++;
                    start=f[0];
                    end=f[1];
                } else if(start==f[0] && end<f[1]) {
                    end=f[1];
                }
            } else {
                count++;
                start=f[0];
                end=f[1];
            }
        }

        count++;
        return count;
    }
};

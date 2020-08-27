// Finding Right Interval for given conditions
// SlothyCoder16
// August 29, 2020


class Solution {
public:
    int binarySearch(vector<int> starts, int x) {
        int start = 0;
        int end = starts.size()-1;

        while(end >= start) {
            int mid = (start + end) / 2;

            if(starts[mid] > x) {
                end = mid - 1;
            } else if(starts[mid] < x) {
                start = mid + 1;
            } else{
                return mid;
            }
        }

        if(start >= starts.size()) return -1;
        return start;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        if(intervals.size() == 1) return {-1};
        unordered_map<int, int> umap;
        vector<int> start;
        for(int i=0; i<intervals.size(); i++) {
            umap[intervals[i][0]] = i;
            start.push_back(intervals[i][0]);
        }
        sort(start.begin(), start.end());

        for(int i=0; i<intervals.size(); i++) {
            int index = binarySearch(start, intervals[i][1]);
            if(index == -1) {
                res.push_back(-1);
            } else {
                res.push_back(umap[start[index]]);
            }
        }

        return res;
    }
};

// Height Checker for an array of students
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        int count=0;
        for(int i=0; i<heights.size(); i++) {
            if(temp[i] != heights[i]) count++;
        }

        return count;
    }
};

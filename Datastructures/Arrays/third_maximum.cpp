// Third maximum nuumber in array
// SlothyCoder16
// September 16, 2020

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i=0; i<nums.size(); i++) s.insert(nums[i]);
        vector<int> temp;
        for(auto it=s.begin(); it!=s.end(); it++) temp.push_back(*it);
        sort(temp.begin(), temp.end(), greater<int>());
        if(temp.size()<3) return temp[0];
        return temp[2];
    }
};

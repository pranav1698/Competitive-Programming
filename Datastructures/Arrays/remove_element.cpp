// SlothyCoder16
// May 21, 2020

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        if(nums.empty()) return 0;
        while(i < nums.size())
            if(nums[i] == val)
                break;
            else
                i = i+1;
        int j=i;
        i = i + 1;

        while(i <nums.size()){
            if(nums[i] == val){
                i = i + 1;
            } else {
                nums[j] = nums[i];
                j = j+1;
                i = i+1;
            }
        }
        //cout << j << endl;
        return j;
    }
};

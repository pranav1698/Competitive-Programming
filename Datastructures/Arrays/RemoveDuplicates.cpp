// Remove Duplicates
// SlothyCoder16
// May 21, 2020

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j = 0;
        int count =0;
        if(nums.empty())
            return 0;
        while(i<nums.size()){
            if(nums[i] == nums[j]){
                i = i+1;
            } else {
                count = count + 1;
                nums[count] = nums[i];
                j = i;
            }
        }
        count = count + 1;
        //cout << count << endl;
        for(int k=count; k<nums.size(); k++){
            nums[k] = 0;
        }
        return count;
    }
};

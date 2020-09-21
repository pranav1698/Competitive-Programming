// Two Sum
// SlothyCoder16
// September 22, 2020

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int>::iterator it;
        for(it=nums.begin(); it!=nums.end(); it++)
            m[*it] = m[*it] + 1;

        vector<int> n(2);
        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];
            if(m[rem] >= 1){
                n[0] = i;
                vector<int>::iterator itr = find(nums.begin(), nums.end(), rem);
                if(itr != nums.cend()){
                    int maybe_answer = distance(nums.begin(), itr);
                    if(maybe_answer != i){
                        n[1] = maybe_answer;
                        break;
                    }
                }
            }
        }
        sort(n.begin(), n.end());
        return n;
    }
};

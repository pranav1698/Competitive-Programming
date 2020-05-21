vector<vector <int>> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int>::iterator it;
    for(it=nums.begin(); it!=nums.end(); it++)
        m[*it] = m[*it] + 1;

    vector<vector<int>> res;
    for(int i=0; i<nums.size(); i++){
        vector<int> n{0,0};
        int rem = target - nums[i];
        if(m[rem] >= 1){
            vector<int>::iterator itr = find(nums.begin(), nums.end(), rem);
            if(itr != nums.cend()){
                int maybe_answer = distance(nums.begin(), itr);
                if(maybe_answer != i){
                    n[1] = maybe_answer;
                    n[0] = i;
                    res.push_back(n);
                }
            }
        }
    }
    return res;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> test{0,0};
        bool flag = true;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int rem = 0 - nums[i];
            vector<vector<int>> twoS = twoSum(nums, rem);
            for(int k=0; k<twoS.size(); k++){
                vector<int> possible_res;
                vector<int> sum = twoS[k];
                if(sum != test){
                    for(int j=0; j<2; j++){
                        if(i != sum[j]){
                            possible_res.insert(possible_res.begin(), nums[sum[j]]);
                        } else {
                            possible_res.clear();
                            break;
                        }
                    }
                    if(!possible_res.empty()){
                        possible_res.push_back(nums[i]);
                    }
                    if(!res.empty() && !possible_res.empty()){
                        for(int i=0; i<res.size(); i++){
                            if(res[i] == possible_res){
                                flag = false;
                                break;
                            } else {
                                flag = true;
                            }
                        }
                    } else {
                        if(!possible_res.empty()){
                            res.push_back(possible_res);
                            flag=false;
                        }
                    }
                    if(flag && !possible_res.empty())
                        res.push_back(possible_res);
                }
            }
        }
        return res;
    }
};

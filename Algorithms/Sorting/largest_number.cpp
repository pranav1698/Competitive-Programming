// Finding largest number from given set of numbers
// SlothyCoder16
// August 09, 2020

class Solution {
public:
    static bool compare(string a, string b) {
        string f = a+b;
        string s = b+a;
        return f>s;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> combins;
        for(int i=0; i<nums.size(); i++) {
            combins.push_back(to_string(nums[i]));
        }
        sort(combins.begin(), combins.end(), compare);

        string res;
        for(int i=0; i<combins.size(); i++)
            res = res + combins[i];

        while(res[0] == '0' && res.size() > 1) {
            res.erase(0, 1);
        }

        return res;
    }
};

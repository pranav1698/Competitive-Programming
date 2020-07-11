// Finding number with single frequency
// SlothyCoder16
// July 11, 2020

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = m[nums[i]] + 1;

        map<int, int>::iterator it = m.begin();
        while(it!=m.end()) {
            if(it->second == 1)
                return it->first;
            it++;
        }

        return -1;
    }
};

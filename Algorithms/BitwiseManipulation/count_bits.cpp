// Count Bits using Kerninghan's algo
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);

        for(int i=1; i<=num; i++){
            int count = 0;
            int x = i;
            while(x != 0){
                count++;
                x = x & (x-1);
            }
            res.push_back(count);
        }

        return res;
    }
};

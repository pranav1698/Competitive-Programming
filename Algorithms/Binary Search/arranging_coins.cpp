// Arranging coins using Bruteforce
// SlothyCoder16
// July 14, 2020


class Solution {
public:
    int arrangeCoins(int n) {
        unsigned long long int count =0;
        unsigned long long int i = 1;
        unsigned long long int ans;

        while(count<=n) {
            count = count + i;
            i+=1;
        }

        if(count==n) {
            ans = i-1;
        } else {
            ans = i-2;
        }

        return ans;
    }
};

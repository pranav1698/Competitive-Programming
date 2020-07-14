// Bitwise AND of range of numbers
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned long long int ans = m;
        unsigned long long int i = m+1;
        while(i<=n) {
            ans = ans & i;
            if(ans == 0)
                break;
            i++;
        }

        return ans;
    }
};

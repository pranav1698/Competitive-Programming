// XOR operation for an array
// SlothyCoder16
// July 16, 2020


class Solution {
public:
    int xorOperation(int n, int start) {
        int i=1;
        unsigned long long int ans = start;

        while(i<n) {
            unsigned long long int num = start + 2*i;
            ans = ans ^ num;
            i++;
        }

        return ans;
    }
};

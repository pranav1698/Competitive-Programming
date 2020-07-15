// Addition of two numbers using bitwise operators
// SlothyCoder16
// July 15, 2020


class Solution {
public:
    int getSum(int x, int y) {
        while(y != 0) {
            unsigned long long int carry = x&y;
            x = x^y;
            y = carry << 1;
        }

        return x;
    }
};

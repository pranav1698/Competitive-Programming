// Power of four using log without any loop
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) {
            return false;
        }

        int n = log(num) / log(4);
        return pow(4, n) == num;
    }
};

// Power of four with loop
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) {
            return false;
        }

        if((num & (num-1)) == 0) {
            int i = 0;
            while((1<<i) < num)
                i++;
            if((i&1) == 0){
                return true;
            } else {
                return false;
            }
        }

        return false;
    }
};

// 1's Complement of given 32 bit number
// SlothyCoder16
// July 16, 2020

class Solution {
public:
    int findComplement(int num) {
        int i=0;
        unsigned long long int nearestPower = 1;
        while(nearestPower<=num) {
            nearestPower = 1 << i;
            i++;
        }

        return (num ^ (nearestPower - 1));
    }
};

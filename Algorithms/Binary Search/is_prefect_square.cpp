// Finding if perfect square using Binary Search
// SlothyCoder16
// July 14, 2020

class Solution {
public:
    bool isPerfectSquare(int num) {
        int min = 0;
        unsigned long long int max = num;

        int m = 1000000007;

        while(max >= min) {
            unsigned long long int  guess = (max + min) / 2;
            unsigned long long int  square = guess * guess;
            if(square > num) {
                max = guess - 1;
            } else if (square < num) {
                min = guess + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

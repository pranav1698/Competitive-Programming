// Square root of a number using Binary Search
// SLothyCoder16
// July 9, 2020

class Solution {
public:
    int mySqrt(int x) {
        int min = 1;
        int max = x;

        while(max >= min) {
            int mid = min + (max - min) / 2;
            if(pow(mid, 2) > x) {
                max = mid  - 1;
            } else if(pow(mid, 2) < x) {
                min = mid + 1;
            } else {
                return mid;
            }
        }

        return max;
    }
};

// Iterative Solution to First Bad Search
// SlothyCoder16
// July 9, 2020

class Solution {
public:
    int firstBadVersion(int n) {
        int MOD=1000000007;
        int min = 1;
        int max = n;

        while(max > min) {
            int guess = min + (max - min) / 2;

            if(isBadVersion(guess)) {
                max = guess;
            } else {
                min = guess + 1;
            }
        }
        return min;
    }
};

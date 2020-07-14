// Guessing number if higher or lower
// SlothyCoder16
// July 14, 2020

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned long long int min = 1;
        unsigned long long int max = n;

        while(max >= min) {
            unsigned long long int mid = min + (max - min) / 2;

            if(guess(mid) == -1) {
                max = mid - 1;
            } else if(guess(mid) == 1) {
                min = mid + 1;
            } else if(guess(mid) == 0) {
                return mid;
            }
        }

        return -1;
    }
};

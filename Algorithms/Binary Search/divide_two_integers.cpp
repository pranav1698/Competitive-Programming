// Dividing two integers using Binary Search
// This does not work for case like -2147483648
// SlothyCoder16
// July 11, 2020

class Solution {
public:
    int divide(int dividend, int divisor) {
        const unsigned int M = 1000000000007;
        int  dDend, dSor;

        dDend = abs(dividend);
        dSor = abs(divisor);

        int min, max;
        if(divisor > 0) {
            min = dSor;
            max = dDend;
        } else {
            min = 0;
            max = dDend;
        }

        if(dDend < dSor)
            return 0;


        int guess;
        while(max >= min) {
            guess = min + (max - min) / 2;
            if((guess * dSor) > dDend) {
                max = guess  - 1;
            } else if((guess * dSor) < dDend) {
                min = guess + 1;
            } else if((guess * dSor) == dDend) {
                if(divisor < 0 || dividend < 0){
                    if(divisor < 0 && dividend < 0)
                        return guess;
                    guess = -1 * guess;
                }

                return guess;
            }
        }

        if(divisor < 0 || dividend < 0){
            if(divisor < 0 && dividend < 0)
                return max;
            max = -1 * max;
        }


        return max;
    }
};

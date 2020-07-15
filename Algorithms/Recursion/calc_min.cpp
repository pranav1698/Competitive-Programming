// Calculate Minimum with present conditions
// SlothyCoder16
// July 16, 2020

class Solution {
public:
    int calcMin(int n) {
        if(n == 1)
            return 0;

        if((n&1) == 0) {
            return 1 + calcMin(n / 2);
        }

        if(n == INT_MAX)
            return calcMin(n-1);

        return 1 + min(calcMin(n + 1), calcMin(n - 1));
    }

    int integerReplacement(int n) {
        int minCount = calcMin(n);

        return minCount;
    }
};

// Find nth tribonnaci number
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        if(n == 5) return 7;
        if(n == 6) return 13;

        return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};

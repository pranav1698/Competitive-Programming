// Base 10 complement number
// SlothyCoder16
// October 05, 2020

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0) return 1;

        int num=N;
        int count=0;
        while(num!=0) {
            count++;
            num=num/2;
        }

        int exp=pow(2,count) -1;

        return N^exp;
    }
};

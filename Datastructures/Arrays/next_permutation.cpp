// Next Permutation of the given number
// SlothyCoder16
// September 23, 2020

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            int n = num.size();
            int i,j;
            i=n-1;
            while(i>0 && num[i]<=num[i-1]) i--;


            if(i==0) {
                reverse(num.begin(), num.end());
                return;
            }

            j=n-1;
            while(j>=i && num[j]<=num[i-1]) j--;

            swap(num[i-1], num[j]);
            reverse(num.begin()+i, num.end());
        }
};

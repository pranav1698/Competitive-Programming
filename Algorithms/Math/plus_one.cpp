// Adding one to array number
// SlothyCoder16
// August 31, 2020

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int j;
        if(digits[n-1] == 9) {
            j = n-1;
            while(j>=0 && digits[j] == 9) {
                digits[j] = 0;
                j--;
            }

            if(j >= 0) {
                digits[j] += 1;
            } else {
                digits.push_back(1);
                digits[0]=1;
                digits[digits.size()-1]=0;
            }
        } else {
            digits[n-1] += 1;
        }

        return digits;
    }
};

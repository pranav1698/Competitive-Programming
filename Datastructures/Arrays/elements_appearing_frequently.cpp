// Elements appearing more than 25% in array
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int num=0;
        int count=0;

        for(int i=0; i<arr.size(); i++) {
            if(arr[i]==num) {
                count++;
            } else {
                if(count > (0.25*arr.size())) return num;
                count=1;
                num=arr[i];
            }
        }

        if(count > (0.25*arr.size())) return num;
        return 0;
    }
};

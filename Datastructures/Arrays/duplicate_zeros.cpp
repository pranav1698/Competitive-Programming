// Duplicate occurence of zeros
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int j=0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]==0 && j+1<arr.size()) {
                arr.pop_back();
                arr.insert(arr.begin()+j+1, 0);
                j += 2;
                i++;
            } else {
                j++;
            }
        }
    }
};

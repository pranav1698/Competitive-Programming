// Sorting an Array by Parity
// SlothyCoder16
// August 08, 2020

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> even;
        vector<int> odd;
        for(int i=0; i<A.size(); i++) {
            if((A[i] & 1) == 0){
                even.push_back(A[i]);
            } else {
                odd.push_back(A[i]);
            }
        }

        int n = A.size();
        A.clear();
        for(int i=0; i<n/2; i++) {
            A.push_back(even[i]);
            A.push_back(odd[i]);
        }


        return A;
    }
};

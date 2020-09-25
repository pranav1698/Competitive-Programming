// Sort array by Parity
// SlothyCoder16
// September 26, 2020

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0;
        while(i<A.size() && (A[i]&1)==0) i++;
        int j=i;
        while(j<A.size() && (A[j]&1)!=0) j++;

        while(i<A.size() && j<A.size()) {
            if((A[i]&1) != 0 && (A[j]&1) == 0) {
                swap(A[i], A[j]);
                i++;
                j++;
            } else if((A[i]&1)==0) {
                i++;
            } else if((A[j]&1)!=0) {
                j++;
            }
        }

        return A;
    }
};

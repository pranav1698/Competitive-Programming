// Checking if the array is monotonic or not
// SlothyCoder16
// September 18, 2020

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing=true;
        bool decreasing=true;

        int n=A.size();
        for(int i=0; i<n-1; i++) {
            if(A[i]<=A[i+1]) increasing=increasing&&true;
            else increasing=false;
            if(A[i]>=A[i+1]) decreasing=decreasing&&true;
            else decreasing=false;
        }

        if(!increasing && !decreasing) return false;

        return true;
    }
};

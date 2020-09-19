// Detect Mountain Array
// SlothyCoder16
// September 19, 2020

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n=A.size();
        int i=0;
        while(i<n-1) {
            if(A[i]==A[i+1]) return false;
            else if(A[i]>A[i+1]) break;
            i++;
        }

        if(i==0 || i==n-1) return false;
        while(i<n-1) {
            if(A[i]==A[i+1]) return false;
            else if(A[i]<A[i+1]) return false;
            i++;
        }

        return true;
    }
};

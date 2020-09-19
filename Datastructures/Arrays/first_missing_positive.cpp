// Finding first missing positive in array
// SlothyCoder16
// September 19, 2020

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n=A.size();
        for(int i=0; i<A.size(); i++) {
            if(A[i]>0 && A[i]<=n) {
                int pos=A[i]-1;
                if(A[i]!=A[pos]) {
                    swap(A[i], A[pos]);
                    i--;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(A[i] != i+1) return i+1;
        }

        return n+1;
    }
};

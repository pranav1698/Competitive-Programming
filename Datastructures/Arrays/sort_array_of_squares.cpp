// Sort Square of numbers 
// SlothyCoder16
// September 19, 2020


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int i=0; i<A.size(); i++) {
            A[i] = A[i]*A[i];
        }

        sort(A.begin(), A.end());
        return A;
    }
};

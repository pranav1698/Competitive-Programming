// Sum of even numbers after queries
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum=0;
        vector<int> res;
        for(int i=0; i<A.size(); i++) {
            if((A[i]&1) == 0) sum += A[i];
        }

        for(int i=0; i<queries.size(); i++) {
            int val = queries[i][0];
            int index = queries[i][1];
            if((A[index]&1) == 0) {
                sum = sum-A[index];
                A[index]=A[index]+val;
                if((A[index]&1) == 0) sum += A[index];
            } else {
                A[index]=A[index]+val;
                if((A[index]&1) == 0) sum += A[index];
            }
            res.push_back(sum);
        }

        return res;
    }
};

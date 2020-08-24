// Max Sum Rectangle not larger than given limit
// SlothyCoder16
// August 24, 2020

class Solution {
public:

    int maxSumLimitK(vector<int> &v, int k){
        int ans = INT_MIN;
        int currSum = 0;
        set<int> st;
        st.insert(0);

        for(int i = 0; i < v.size(); i++){
            currSum += v[i];
            auto pos =  st.lower_bound(currSum - k);
            if(pos != st.end()) {
                ans = max(ans, currSum - *pos);
            }
            st.insert(currSum);
        }

        return ans;

    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        int maxSum = INT_MIN;

        for(int L = 0; L < m; L++){
            vector<int> sum(n, 0);
            for(int R = L; R < m; R++){
                for(int i = 0; i < n; i++) sum[i] += matrix[i][R];
                int currMax = maxSumLimitK(sum, k);
                maxSum = max(maxSum, currMax);
            }
        }

        return maxSum;

    }
};

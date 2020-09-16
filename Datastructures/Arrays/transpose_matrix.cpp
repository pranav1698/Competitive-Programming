// Transpose of the Matrix
// SlothyCoder16
// September 18, 2020

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        int mt=n;
        int nt=m;

        vector<int> temp;
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                temp.push_back(A[i][j]);

        int count=0;
        vector<vector<int>> res(mt, vector<int>(nt, 0));
        for(int i=0; i<mt; i++) {
            for(int j=0; j<nt; j++) {
                res[i][j]=temp[count];
                count++;
            }
        }

        return res;
    }
};

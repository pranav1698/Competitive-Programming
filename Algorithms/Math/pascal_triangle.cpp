// Finding Pascal Triangle using DP
// SlothyCoder16
// August 12, 2020

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int** arr = new int*[rowIndex+1];

        for(int i=0; i<=rowIndex; i++) {
            arr[i]  = new int[i+1];
            if(i == 0) arr[i][0] = 1;
            if(i == 1) {
                arr[i][0] = 1;
                arr[i][1] = 1;
            }

            if(i > 1) {
                arr[i][0] = 1;
                arr[i][i] = 1;

                for(int j=1; j<i; j++) {
                    arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
                }
            }
        }

        vector<int> res;
        for(int i=0; i<=rowIndex; i++) res.push_back(arr[rowIndex][i]);

        delete[] arr;
        return res;
    }
};

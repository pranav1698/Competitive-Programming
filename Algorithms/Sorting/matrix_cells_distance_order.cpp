// Matrix Cells Distance using sorting
// SlothyCoder16
// August 10, 2020

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;

        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                res.push_back({i,j});
            }
        }

        sort(res.begin(), res.end(), [r0, c0](const vector<int> p1, const vector<int> p2){
            int d1 = abs(p1[0] - r0) + abs(p1[1] - c0);
            int d2 = abs(p2[0] - r0) + abs(p2[1] - c0);
            return d1 < d2;
        });

        return res;
    }
};

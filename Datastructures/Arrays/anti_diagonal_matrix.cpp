// Anti Diagonal elements of matrix
// SlothyCoder16
// September 21, 2020

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> res;

    for(int j=0; j<A[0].size(); j++) {
        vector<int> temp;
        int startx=0;
        int starty=j;
        while(startx<A.size() && starty>=0) {
            temp.push_back(A[startx][starty]);
            startx++;
            starty--;
        }
        res.push_back(temp);
    }

    for(int i=1; i<A.size(); i++) {
        vector<int> temp;
        int startx=i;
        int starty=A[0].size()-1;
        while(startx<A.size() && starty>=0) {
            temp.push_back(A[startx][starty]);
            startx++;
            starty--;
        }
        res.push_back(temp);
    }

    return res;
}

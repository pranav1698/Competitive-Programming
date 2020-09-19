// Noble Integer
// SlothyCoder16
// September 19, 2020

int Solution::solve(vector<int> &A) {
    unordered_map<int, int> umap;
    for(int i=0; i<A.size(); i++) umap[A[i]] += 1;
    sort(A.begin(), A.end());

    int len=A.size();
    int i=0;
    while(i<A.size()){
        if(A[i] == (len-umap[A[i]])) return 1;
        len -= umap[A[i]];
        i+=umap[A[i]];
    }

    return -1;
}

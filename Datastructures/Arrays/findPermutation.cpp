// Find Permutation in the array
// SlothyCoder16
// September 22, 2020

// O(N) approach
vector<int> Solution::findPerm(const string A, int B) {
    vector<int> res;
    int currSmallest=1;
    int currBiggest=B;

    for(int i=0; i<A.length(); i++) {
        if(A[i]=='I') {
            res.push_back(currSmallest);
            currSmallest++;
        } else {
            res.push_back(currBiggest);
            currBiggest--;
        }
    }

    if(A[A.length()-1] == 'D') res.push_back(currSmallest);
    else res.push_back(currBiggest);

    return res;
}

// Sum of maximum and minimum element in the array
// SlothyCoder16
// September 19, 2020

int Solution::solve(vector<int> &A) {
    int max_num=INT_MIN;
    for(int i=0; i<A.size(); i++) max_num=max(max_num, A[i]);
    int min_num=INT_MAX;
    for(int i=0; i<A.size(); i++) min_num=min(min_num, A[i]);

    return max_num+min_num;
}

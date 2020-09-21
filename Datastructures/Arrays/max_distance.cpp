// Maximum distance given the pattern
// SlothyCoder16
// September 22, 2020

// O(NlogN) approach
int Solution::maximumGap(const vector<int> &A) {
    int maxDiff=0;
    vector<pair<int, int>> index;
    for(int i=0; i<A.size(); i++) {
        index.push_back({A[i], i});
    }

    sort(index.begin(), index.end());
    int maxRight=index[index.size()-1].second;
    for(int i=A.size()-2; i>=0; i--) {
        maxRight = max(maxRight, index[i].second);
        maxDiff = max(maxDiff, maxRight-index[i].second);
    }

    return maxDiff;

}


// O(N) approach
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int> right(n);
        right[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--) right[i] = max(right[i+1], arr[i]);

        int i=0, j=0;
        int ans=0;
        while(i<n && j<n) {
            if(arr[i]<=right[j]) {
                ans = max(ans, j-i);
                j++;
            } else  {
                i++;
            }
        }

        return ans;
    }
};

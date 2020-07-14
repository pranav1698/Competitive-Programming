// Find index of peak element in Mountain Array
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int min = 0;
        int max = A.size() - 1;

        while(max >= min) {
            int mid = min + (max - min) / 2;
            if(mid == 0)
                mid = 1;
            if(mid == A.size() - 1)
                mid = A.size() - 2;

            int next = mid + 1;
            int prev = mid - 1;

            if(A[mid] > A[next] && A[mid] > A[prev]) {
                return mid;
            } else if(A[mid] < A[prev]) {
                max = mid - 1;
            } else if(A[mid] < A[next]) {
                min = mid + 1;
            }
        }

        return -1;
    }
};

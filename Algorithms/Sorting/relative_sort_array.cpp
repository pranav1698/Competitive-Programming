// Array Sorted realtive to another Array
// SlothyCoder16
// August 06, 2020

class Solution {
public:
    int binarySearch(vector<int> arr, int start, int end, int x) {
        while(end >= start) {
            int mid = start + (end-start) / 2;

            if(arr[mid] > x) {
                end = mid - 1;
            } else if(arr[mid] < x) {
                start = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        sort(arr1.begin(), arr1.end());
        int n = arr1.size();

        int j=0;

        while(j < arr2.size()) {
            int index = binarySearch(arr1, 0, n-1, arr2[j]);
            if(index == -1) {
                j++;
            } else {
                res.push_back(arr1[index]);
                arr1[index] = INT_MAX;
                sort(arr1.begin(), arr1.end());
                n--;
            }
        }

        for(int i=0; i<n; i++)
            res.push_back(arr1[i]);

        return res;

    }
};

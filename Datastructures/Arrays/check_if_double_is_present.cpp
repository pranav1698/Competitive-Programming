// Check if double is present in array
// SlothyCoder16
// September 26, 2020

class Solution {
public:
    int binarySearch(vector<int> &arr, int x) {
        int start=0;
        int end=arr.size()-1;

        while(start<=end) {
            int mid = start + (end-start)/2;
            if(arr[mid] < x) {
                start=mid+1;
            } else if(arr[mid]>x) {
                end=mid-1;
            } else {
                return mid;
            }
        }

        return -1;
    }

    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr.size() == 1) return false;
        if(arr.size() == 2) {
            if(arr[1] == 2*arr[0]) return true;
            else return false;
        }

        for(int i=1; i<arr.size()-1; i++) {
            if(binarySearch(arr, 2*arr[i]) != -1 && binarySearch(arr, 2*arr[i]) != i) return true;
        }

        return false;
    }
};

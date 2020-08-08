// Finding max difference in Array using merge sort
// SlothyCoder16
// August 08, 2020


class Solution {
public:
    int ans = INT_MIN;
    void merge(vector<int>& arr, int lo, int mid, int high) {
        int temp[(high-lo) +1];
        int i=lo;
        int j = mid+1;
        int k = 0;

        while(i<=mid && j<=high) {
            if(arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
                if(k != 0) ans = max(ans, (temp[k] - temp [k-1]));
                k++;
            } else {
                temp[k] = arr[j];
                j++;
                if(k != 0) ans = max(ans, (temp[k] - temp[k-1]));
                k++;
            }
        }

        while(i <= mid) {
            temp[k] = arr[i];
            i++;
            if(k != 0) ans = max(ans, (temp[k] - temp[k-1]));
            k++;
        }

        while(j <= high) {
            temp[k] = arr[j];
            j++;
            if(k != 0) ans = max(ans, (temp[k] - temp[k-1]));
            k++;
        }

        for(int l=lo; l<=high; l++)
            arr[l] = temp[l - lo];

    }

    void mergeSort(vector<int>& nums, int lo, int high) {
        if(lo >= high) return;

        int mid = lo + (high - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, high);

        merge(nums, lo, mid, high);
    }

    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};

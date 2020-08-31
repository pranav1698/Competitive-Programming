// Merge Sorted Arrays
// SlothyCoder16
// August 31, 2020

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n, 0);
        int i=0;
        int j=0;
        int k=0;

        while(i<m && j<n) {
            if(nums1[i] <= nums2[j]) {
                temp[k] = nums1[i];
                i++;
                k++;
            } else {
                temp[k] = nums2[j];
                j++;
                k++;
            }
        }

        while(i<m) {
            temp[k] = nums1[i];
            i++;
            k++;
        }

        while(j<n) {
            temp[k] = nums2[j];
            j++;
            k++;
        }

        for(int l=0; l<(m+n); l++) nums1[l] = temp[l];
    }
};

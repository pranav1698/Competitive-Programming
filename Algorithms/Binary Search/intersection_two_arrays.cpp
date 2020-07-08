// Intersection of two arrays using binary Search
// SLothyCoder16
// July 9, 2020

class Solution {
public:
    int doSearch(vector<int> arr, int min, int max, int target) {
        while(max>=min) {
            int guess = min + (max - min) / 2;
            if(arr[guess] > target) {
                max = guess  - 1;
            } else if (arr[guess] < target) {
                min = guess + 1;
            } else {
                return guess;
            }
        }

        return -1;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l1 = nums1.size();
        int l2 = nums2.size();
        vector<int> res;

        if(l1 > l2){
            for(int i=0; i < nums2.size(); i++) {
                int index = doSearch(nums1, 0, nums1.size() - 1, nums2[i]);
                if(index != -1){
                    int index_res = doSearch(res, 0, res.size()-1, nums2[i]);
                    if(index_res == -1)
                        res.push_back(nums2[i]);
                }
            }
        } else {
            for(int i =0; i<nums1.size(); i++) {
                int index = doSearch(nums2, 0 , nums2.size() - 1, nums1[i]);
                if(index != -1) {
                    int index_res = doSearch(res, 0, res.size() - 1, nums1[i]);
                    if(index_res == -1)
                        res.push_back(nums1[i]);
                }
            }
        }
        return res;
    }
};

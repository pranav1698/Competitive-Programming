// Intersection of two arrays with duplicates using Binary Search
// SlothyCoder16
// July 14, 2020


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

    vector<int> replace(vector<int> nums, int index) {
        for(int i=index; i<nums.size()-1; i++) {
            nums[i] = nums[i+1];
        }

        return nums;
    }

    void print(vector<int> nums) {
        for(int i=0; i<nums.size(); i++) {
            cout << nums[i] << endl;
        }
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //print(nums2);
        int l1 = nums1.size();
        int l2 = nums2.size();
        vector<int> res;

        if(l1 > l2){
            for(int i=0; i < nums2.size(); i++) {
                int index = doSearch(nums1, 0, nums1.size() - 1, nums2[i]);
                if(index != -1){
                    res.push_back(nums2[i]);
                    nums1 = replace(nums1, index);
                }
            }
        } else {
            for(int i =0; i<nums1.size(); i++) {
                int index = doSearch(nums2, 0 , nums2.size() - 1, nums1[i]);
                // cout << nums2[--l2] << endl;
                if(index != -1) {
                    res.push_back(nums1[i]);
                    nums2 = replace(nums2, index);
                }
            }
        }
        return res;
    }

};

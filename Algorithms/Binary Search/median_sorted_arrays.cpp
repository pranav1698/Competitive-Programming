// Median of two sorted arrays using Modified binary Search
// SlothyCoder16
// July 14, 2020


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size();
        int y = nums2.size();

        double median;

        int start = 0;
        int end  = nums1.size();

        while(end >= start) {
            int partX = (start + end) / 2;
            int partY = (x + y + 1) / 2 - partX;
            // cout << partX << " " << partY << endl;

            int maxLeftX = (partX == 0 ? INT_MIN : nums1[partX - 1]);
            int maxLeftY = (partY == 0 ? INT_MIN : nums2[partY - 1]);

            int minRightX = (partX == x ? INT_MAX : nums1[partX]);
            int minRightY = (partY == y ? INT_MAX : nums2[partY]);

            if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if(((x + y) & 1) == 0) {
                    median = (double)(((double)max(maxLeftX, maxLeftY) +  (double)min(minRightX, minRightY)) / 2);
                    break;
                } else {
                    median = (double)max(maxLeftX, maxLeftY);
                    break;
                }
            } else if (maxLeftX > minRightY) {
                end = partX - 1;
            } else {
                start = partX + 1;
            }
        }

        return median;
    }
};

// Kth largest element in unsorted array
// SlothyCoder16
// August 1, 2020

class Solution {
public:
    void swap(vector<int> &nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void shiftDown(vector<int> &nums, int index, int last) {
        int maxIndex = index;
        int l = 2*index + 1;
        if(l <= last && nums[l] > nums[maxIndex])
            maxIndex = l;
        int r = 2*index + 2;
        if(r <= last && nums[r] > nums[maxIndex])
            maxIndex = r;

        if(index != maxIndex) {
            swap(nums, index, maxIndex);
            shiftDown(nums, maxIndex, last);
        }
    }

    void buildHeap(vector<int> &nums, int size) {
        int last = size - 1;
        int index;
        if((last & 1) == 0) {
            index = (last / 2) - 1;
        } else {
            index = last / 2;
        }

        while(index >= 0) {
            shiftDown(nums, index, last);
            index = index - 1;
        }
    }

    int extractMax(vector<int> &nums, int* size) {
        int last = *size - 1;
        int res = nums[0];
        nums[0] = nums[last];
        *size = *size - 1;
        shiftDown(nums, 0, *size);
        return res;
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;

        if(k == 0) return -1;

        int res;
        int size = nums.size();
        buildHeap(nums, size);

        int i = 0;
        while(i != k) {
            res = extractMax(nums, &size);
            i = i + 1;
        }

        return res;
    }
};

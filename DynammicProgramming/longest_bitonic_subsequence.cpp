#include <bits/stdc++.h>
using namespace std;

int lengthOfLBS(vector<int> &nums) {
  vector<int> lis(nums.size(), 1);
  vector<int> output(nums.size(), 1);

  // Finding length of longest increasing subsequence at current index
  // because the bitonic subsequence is increaing then decresing
  for(int i=1; i<nums.size(); i++) {
    for(int j=0; j<i; j++) {
      if(nums[j] < nums[i]) lis[i] = max(lis[i], lis[j] + 1);
    }
  }

  for(int i=0; i<nums.size(); i++) {
    for(int j=0; j<i; j++) {
      if(nums[j] > nums[i]) {
        output[i] = max(output[i], output[j] + 1);
      } else {
        output[i] = max(output[i], lis[j] + 1);
      }
    }
  }

  int best = INT_MIN;
  for(int i=0; i<nums.size(); i++) best = max(best, output[i]);

  return best;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  int curr;
  for(int i=0; i<n; i++) {
    cin >> curr;
    nums.push_back(curr);
  }

  cout << lengthOfLBS(nums) << endl;
}

// SlothyCoder16
// May 20, 2020
// Brute Force
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int area = INT_MIN;
//         for(int i=height.size() - 1; i>=0; i--){
//             int h=height[i];
//             for(int j=0;j<=i;j++){
//                 if(height[j]>=h)
//                     area = max(area, h*(i-j));
//                 else
//                     area = max(area, height[j]*(i-j));
//             }
//         }
//         return area;
//     }
// };

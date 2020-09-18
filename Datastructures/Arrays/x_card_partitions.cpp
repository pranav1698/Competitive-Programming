// If you can make a x card partitioning 
// SlothyCoder16
// September 18, 2020



class Solution {
public:
    int gcd(int x, int y) {
      int dividend = max(x, y);
      int divisor = min(x,y);
      int remainder = dividend % divisor;
      if (remainder == 0) {
        return divisor;
      }
      return gcd(divisor, remainder);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
      unordered_map<int, int> counts;
      for(int n : deck) {
        counts[n]++;
      }
      int current_group_size = 0;
      for(auto& entry : counts) {
        if(current_group_size == 0) {
          current_group_size = entry.second;
        } else {
          current_group_size = gcd(current_group_size, entry.second);
        }
      }
      return current_group_size > 1;
    }
};

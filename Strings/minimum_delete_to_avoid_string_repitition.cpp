// Minimum delete to avoid string repitition
// SlothyCoder16
// September 15, 2020

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int min_cost=0;
        int n=s.size();
        if(n==0 || n==1) return 0;
        int i=0;
        int j=1;

        while(i<n && j<n) {
            if(s[i] == s[j]) {
                if(cost[i]<=cost[j]) {
                    min_cost += cost[i];
                } else {
                    min_cost += cost[j];
                    int temp = cost[j];
                    cost[j] = cost[i];
                    cost[i] = temp;
                }
            }
            i++;
            j++;
        }

        return min_cost;
    }
};

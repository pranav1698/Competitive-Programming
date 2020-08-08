// Filter restaurants by parameters
// SlothyCoder16
// August 08, 2020

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> res;
        vector<int> ans;

        for(int i=0; i<restaurants.size(); i++) {
            if(veganFriendly == 1) {
                if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance && restaurants[i][2] == 1) res.push_back(restaurants[i]);
            } else {
                if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) res.push_back(restaurants[i]);
            }
        }

        sort(res.begin(), res.end(), [](const vector<int> &f, const vector<int> &s) {
            if(f[1] == s[1]) return f[0] > s[0];

            return f[1] > s[1];
        });

        for(int i=0; i<res.size(); i++) ans.push_back(res[i][0]);

        return ans;
    }
};

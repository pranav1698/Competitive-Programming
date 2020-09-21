// Car Pooling depending on the capacity
// SlothyCoder16
// September 22, 2020

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int currPool=0, maxPool=0;
        vector<vector<int>> bookTrips;

        for(int i=0; i<trips.size(); i++) {
            bookTrips.push_back({trips[i][1], 1, trips[i][0]});
            bookTrips.push_back({trips[i][2], 0, trips[i][0]});
        }

        sort(bookTrips.begin(), bookTrips.end());
        for(int i=0; i<bookTrips.size(); i++) {
            if(bookTrips[i][1] == 1) {
                currPool += bookTrips[i][2];
                maxPool = max(currPool, maxPool);
            } else {
                currPool-= bookTrips[i][2];
            }
        }

        if(maxPool > capacity) return false;
        return true;
    }
};

// Teemo Attacking
// SlothyCoder16
// September 26, 2020

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;
        int time=duration;
        int start=timeSeries[0];
        int end=start+duration;

        for(int i=1; i<timeSeries.size(); i++) {
            start=timeSeries[i];
            if(end > start) {
                time += duration - (end-start);
            } else {
                time += duration;
            }
            end=timeSeries[i]+duration;
        }

        return time;
    }
};

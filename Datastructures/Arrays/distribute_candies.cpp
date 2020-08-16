// Distribute Candies to people
// SlothyCoder16
// August 17, 2020

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int n = 1;
        int candies_left = candies;

        int i=0;
        int j=1;
        while(candies_left >= n) {
            i=0;
            while(i<num_people && candies_left >= n) {
                res[i] = res[i] + j;
                candies_left = candies_left - j;
                i= (i+1) % num_people;
                j = j+1;
                n = j;
            }
        }

        res[i] = res[i] + candies_left;


        return res;
    }
};

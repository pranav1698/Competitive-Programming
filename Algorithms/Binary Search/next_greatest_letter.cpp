// Find next greatest letter using binary search
// SlothyCoder16
// July 16, 2020 

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int min = 0;
        int max = letters.size() - 1;

        while(max >= min) {
            int guess = min + (max - min) / 2;

            if(letters[guess] > target) {
                max = guess - 1;
            } else if(letters[guess] <= target) {
                min = guess + 1;
            }
        }


        return letters[min%letters.size()];
    }
};

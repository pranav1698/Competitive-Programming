// Detecting if the given string is capital or not (following the capital pattern)
// SlothyCoder16
// August 02, 2020

class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<int> capitals;

        for(int i=0; i<word.size(); i++) {
            int asciiValue = (int)word[i];
            if(asciiValue >= 65 && asciiValue <= 90) {
                capitals.push_back(asciiValue);
            }
        }

        int capitalSize = capitals.size();

        if(capitalSize == word.size()) {
            return true;
        } else if(capitalSize == 0) {
            return true;
        } else if(capitalSize == 1) {
            int firstAscii = (int)word[0];
            if(firstAscii >= 65 && firstAscii <= 90)
                return true;
        }

        return false;
    }
};

// Bulls and Crows
// SlothyCoder16
// September 10, 2020

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> umap;
        int bulls=0;
        int cows=0;

        for(int i=0; i<guess.size(); i++) {
            if(guess[i] == secret[i]) {
                bulls++;
            } else {
                umap[secret[i]]++;
            }
        }

        for(int i=0; i<guess.size(); i++){
            if(secret[i]!=guess[i] && umap[guess[i]]>0) {
                cows++;
                umap[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

// Letter Combinations of phone number
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    vector<string> ans;
    void stringPermute(unordered_map<int, vector<char>> &umap, string soFar, string rest) {
        if(rest == "") {
            ans.push_back(soFar);
            return;
        }

        int firstNumber = rest[0] - '0';
        for(int i=0; i<umap[firstNumber].size(); i++) {
            string temp = soFar + umap[firstNumber][i];
            stringPermute(umap, temp, rest.substr(1));
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;

        unordered_map<int, vector<char>> umap;
        umap[2] = {'a', 'b', 'c'};
        umap[3] = {'d', 'e', 'f'};
        umap[4] = {'g', 'h', 'i'};
        umap[5] = {'j', 'k', 'l'};
        umap[6] = {'m', 'n', 'o'};
        umap[7] = {'p', 'q', 'r', 's'};
        umap[8] = {'t', 'u', 'v'};
        umap[9] = {'w', 'x', 'y', 'z'};


        stringPermute(umap, "", digits);
        return ans;
    }
};

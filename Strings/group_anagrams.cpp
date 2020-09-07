// Grouping Anagrams using hashtable
// SlothyCoder16
// September 07, 2020

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for(int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            umap[temp].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto it=umap.begin(); it!=umap.end(); it++) res.push_back(it->second);
        return res;
    }
};

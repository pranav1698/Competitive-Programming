// Finding maximum prooduct of lengths for array of strings using binary search (Bruteforce)
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    bool containsCommon(string a, string b){
        for(int i=0; i<a.length(); i++){
            int start = 0;
            int end = b.length()-1;

            while(end >= start) {
                int mid = start + (end - start) / 2;
                if(b[mid] > a[i]) {
                    end = mid - 1;
                } else if (b[mid] < a[i]) {
                    start = mid + 1;
                } else {
                    return true;
                }
            }
        }

        return false;
    }

    int maxProduct(vector<string>& words) {
        int ans = INT_MIN;

        if(words.size() == 0)
            return 0;

        for(int i=0; i<words.size(); i++)
            sort(words[i].begin(), words[i].end());

        for(int i=0; i<words.size()-1; i++){
            for(int j=i+1; j<words.size(); j++) {
                if(!containsCommon(words[i], words[j])){
                    int product = words[i].length() * words[j].length();
                    ans = max(ans,product);
                }

            }
        }

        if(ans == INT_MIN)
            return 0;

        return ans;
    }
};

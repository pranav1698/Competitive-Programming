// Finding kth grammar word using recursion
// SlothyCoder16
// August 18, 2020

// TLE solution
class Solution {
public:
    string nthWord(int N) {
        if(N == 0) return "0";

        string recurAns = nthWord(N-1);
        string ans = "";
        for(int i=0; i<recurAns.length(); i++) {
            if(recurAns[i] == '0') {
                ans = ans + "01";
            } else if(recurAns[i] == '1'){
                ans = ans + "10";
            }
        }

        return ans;
    }

    int kthGrammar(int N, int K) {
        string res = nthWord(N-1);

        return res[K-1] - '0';
    }
};

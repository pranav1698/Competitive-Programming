// Finding longest word in dictionary through deleting
// SlothyCoder16
// August 10, 2020

class Solution {
public:
    string findLongestWord(string S, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string s1, const string s2) {
            if(s1 == s2) return true;
            if(s1.length() == s2.length()) {
                int i=0;
                while(s1[i] == s2[i]) {
                    i++;
                }

                return s1[i] > s2[i];
            }

            return s1.length() < s2.length();
        });

        string str;
        for (int i = 0; i < d.size(); i++) {
            string res = d[i];
            if(res.length() > S.length()) continue;
            int count = 0, idx = 0;
            for(int j=0; j<res.length() && idx<S.length(); j++) {
                int id = S.find(res[j], idx);
                if(id != string::npos) {
                    count++;
                    idx = id + 1;
                } else {
                    idx = S.length();
                }
            }

            if(count == res.length()) str = res;
        }

        return str;
    }
};

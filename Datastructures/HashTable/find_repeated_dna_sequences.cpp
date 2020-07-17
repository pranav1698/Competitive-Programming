// Find reqpeated dna subsequences using hashmap 
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        map<string, int> m;

        if(s.length() < 10)
            return res;

        for(int i=0; i<=s.length()-10; i++){
            string substr = "";
            for(int j=i; j<10+i;j++){
                substr = substr + s[j];
            }
            m[substr] = m[substr] + 1;
        }

        map<string, int>::iterator it = m.begin();
        while(it != m.end()) {
            if(it->second > 1){
                res.push_back(it->first);
            }
            it++;
        }

        return res;
    }
};

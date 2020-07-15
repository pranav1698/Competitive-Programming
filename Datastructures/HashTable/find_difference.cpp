// Find Difference between two strings using hashtable
// SlothyCoder16
// July 15, 2020

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res;
        map<char, int> s_map;
        map<char, int> t_map;

       for(int i=0; i<s.length(); i++)
           s_map[s[i]] = s_map[s[i]] + 1;

        for(int i=0; i<t.length(); i++)
            t_map[t[i]] = t_map[t[i]] + 1;

        map<char, int>::iterator it = t_map.begin();
        while(it != t_map.end()) {
            char subchar = it->first;
            //cout << s_map[subchar] << t_map[subchar] << endl;
            if(s_map[subchar] != t_map[subchar])
                res = subchar;
            it++;
        }


        return res;
    }
};

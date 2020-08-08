// Formation of increasing decreasing string
// SlothyCoder16
// Auguust 09, 2020

class Solution {
public:
string sortString(string s) {

	string g="";
    set<char,greater<>> m;
    set<char> k;
    while(s.length()>0)
    {
        m.clear();
        k.clear();
        k.insert(s.begin(),s.end());
        for(auto i:k)
        {
            g+=i;
            s.erase(s.find(i),1);
        }
        m.insert(s.begin(),s.end());
        for(auto i:m)
        {
            g+=i;
            s.erase(s.find(i),1);
        }
    }
    return g;
}
};

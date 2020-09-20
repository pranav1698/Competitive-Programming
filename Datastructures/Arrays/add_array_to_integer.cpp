// Add integer to array
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        string s="";
        for(int i=0; i<A.size(); i++) s += to_string(A[i]);
        string s1=to_string(K);

        int n1=s.length()-1;
        int n2=s1.length()-1;
        int carry=0;
        string ans="";

        while(n1>=0 && n2>=0) {
            int curr1=s[n1]-'0';
            int curr2=s1[n2]-'0';
            int curr = curr1+curr2+carry;
            ans += to_string(curr%10);
            carry = curr/10;
            n1--;
            n2--;
        }

        while(n1!=-1) {
            int curr = s[n1]-'0' + carry;
            ans += to_string(curr%10);
            carry = curr/10;
            n1--;
        }

        while(n2!=-1) {
            int curr = s1[n2]-'0' + carry;
            ans += to_string(curr%10);
            carry = curr/10;
            n2--;
        }

        if(carry!=0) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++) res.push_back(ans[i]-'0');
        return res;
    }
};

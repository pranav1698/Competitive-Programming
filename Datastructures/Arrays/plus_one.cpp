// Adding plus one in the given vector numbers
// SlothyCoder16
// September 08, 2020

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> res;
    string n="";
    if(A.size()==1 && A[0] == 0) return {1};
    for(int i=0; i<A.size(); i++) n+=to_string(A[i]);
    int k=0;
    while(k<A.size() && A[k]==0) k++;
    n = n.substr(k);

    int carry=1;
    int len=n.size();
    string s="";
    while(carry != 0 && len>0) {
        int sum = (n[len-1]-'0') + carry;
        carry = sum/10;
        s += to_string(sum%10);
        len--;
    }

    if(carry!=0) s+=to_string(carry);
    for(int i=0; i<len; i++) res.push_back(n[i]-'0');
    reverse(s.begin(), s.end());
    for(int i=0;i<s.size(); i++) res.push_back(s[i]-'0');
    return res;
}

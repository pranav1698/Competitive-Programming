// Adding two binaries
// SlothyCoder16
// September 07, 2020

class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size();
        int n2=b.size();

        string ans="";
        int carry=0;
        int sum;
        while(n1!=0 && n2!=0) {
            sum = (a[n1-1]-'0') + (b[n2-1]-'0') + carry;
            if(sum == 2) {
                sum = 0;
                carry = 1;
            } else if(sum == 3) {
                sum = 1;
                carry = 1;
            } else {
                carry=0;
            }
            ans += to_string(sum);
            n1--;
            n2--;
        }

        while(n1!=0){
            sum = (a[n1-1]-'0') + carry;
            if(sum == 2) {
                sum = 0;
                carry = 1;
            } else if(sum == 3) {
                sum = 1;
                carry = 1;
            } else {
                carry=0;
            }
            ans += to_string(sum);
            n1--;
        }

        while(n2!=0) {
            sum = (b[n2-1]-'0') + carry;
            if(sum == 2) {
                sum = 0;
                carry = 1;
            } else if(sum == 3) {
                sum = 1;
                carry = 1;
            } else {
                carry = 0;
            }
            ans+=to_string(sum);
            n2--;
        }

        if(carry!=0) ans+=to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

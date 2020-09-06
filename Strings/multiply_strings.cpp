// Multiplying two strings bigger solution
// SlothyCoder16
// September 06, 2020

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]-'0' == 0) return "0";
        if(num2[0]-'0' == 0) return "0";
        int len1 = num1.length();
        int len2 = num2.length();
        vector<string> products;
        int t1 = len1;

        while(t1 != 0) {
            int curr1 = num1[t1-1]-'0';
            int carry = 0;
            string p1="";
            for(int i=len2-1; i>=0; i--) {
                int curr2 = num2[i]-'0';
                int a1 = curr1*curr2 + carry;
                carry = a1/10;
                p1+=to_string(a1%10);
            }
            if(carry!=0) p1+=to_string(carry);
            reverse(p1.begin(), p1.end());
            for(int j=(len1-t1); j>0; j--) p1 += '0';
            products.push_back(p1);
            t1--;
        }

        string ans=products[0];
        int carry;
        for(int i=1; i<products.size(); i++) {
            string s=products[i];
            string t="";
            int n1 = ans.length();
            int n2 = s.length();
            carry = 0;
            while(n1!=0 && n2!=0) {
                int c1 = ans[n1-1] - '0';
                int c2 = s[n2-1] - '0';
                int c3 = c1 + c2 + carry;
                carry = c3/10;
                t+=to_string(c3%10);
                n1--;
                n2--;

            }
            while(n1!=0) {
                int c1 = ans[n1-1] - '0';
                int c2 = c1 + carry;
                carry = c2/10;
                t += to_string(c2%10);
                n1--;
            }
            while(n2!=0) {
                int c1 = s[n2-1] - '0';
                int c2 = c1 + carry;
                carry = c2/10;
                t += to_string(c2%10);
                n2--;
            }
            if(carry!=0) t+=to_string(carry);
            reverse(t.begin(), t.end());
            ans = t;
        }


        return ans;
    }
};

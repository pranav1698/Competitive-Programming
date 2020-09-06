// Multiplying two strings faster solution
// SlothyCoder16
// September 06, 2020

class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        vector<int> pos(m+n, 0);

        int pos1, pos2, sum=0;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int product = (num1[i]-'0')*(num2[j]-'0');
                pos1=i+j;
                pos2=i+j+1;
                sum = product + pos[pos2];
                pos[pos1] += sum/10;
                pos[pos2] = sum%10;
            }
        }
        string res="";
        int i=0;
        while(i<m+n && pos[i]==0) i++;
        for(int j=i; j<m+n; j++) res+=to_string(pos[j]);


        return res.size() == 0 ? "0" : res;
    }
};

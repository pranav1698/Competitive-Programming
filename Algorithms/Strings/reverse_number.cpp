// Reverse number
// SlothyCoder16
// August 29, 2020

class Solution {
public:
    int reverse(int x) {
        int temp = x;
        string s = to_string(abs(temp));
        std::reverse(s.begin(), s.end());

        int reverse = 0;
        try {
            reverse = stoi(s);
        } catch(...) {
            return 0;
        }

        if(x < 0) return (-reverse);

        return reverse;
    }
};

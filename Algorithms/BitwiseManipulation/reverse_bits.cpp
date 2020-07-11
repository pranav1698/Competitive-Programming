// Reversing bits of unsigned 32 bit number using bitwise manipulation
// SlothyCoder16
// July 11, 2020

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
     uint32_t a = 0,k=32;
        while(k--){
            a=((a<<1)|(n&1));
            n=(n>>1);
        }
        return a;
    }
};

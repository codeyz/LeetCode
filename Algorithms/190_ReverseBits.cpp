/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res = 0;
        res = n & 1;
        for(int i = 1;i < 32; ++i)
        {
            n >>= 1;
            res = (res << 1) + (n & 1);
        }
        return res;
    }
};
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        n = (n >> 1 & 0x55555555) + (n << 1 & 0xAAAAAAAA);
        n = (n >> 2 & 0x33333333) + (n << 2 & 0xCCCCCCCC);
        n = (n >> 4 & 0x0F0F0F0F) + (n << 4 & 0xF0F0F0F0);
        n = (n >> 8 & 0x00FF00FF) + (n << 8 & 0xFF00FF00);
        n = (n >> 16 & 0x0000FFFF) + (n << 16 & 0xFFFF0000);
        return n;
    }
};

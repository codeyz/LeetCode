/*
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int sum = 0;
        while(n)
        {
            sum += n & 1;
            n >>= 1;
        }
        return sum;
    }
};
*/

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int m[5] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};
        for(int i = 0, flag = 1;i < 5; ++i, flag <<= 1)
        {
            n = (n & m[i]) + ((n >> flag) & m[i]);
        }
        return n;
    }
};

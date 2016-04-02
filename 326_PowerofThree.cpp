class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        // 1162261467 is the maximum integer which is a power of three
        return n > 0 && !(1162261467 % n);
    }
};

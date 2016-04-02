/*
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        while(n > 1 && n % 2 == 0)
        {
            n /= 2;
        }
        return n == 1;
    }
};
*/

/*
 * for a number {n} which is a power of two, it can be concluded that:
 * 1. the highest bit is 1 and other bits are 0
 * 2. for {n - 1} all bits are 1 except the highest one
 * 3. so if n is a power of two, n & (n - 1) == 0
 * 4. if n is not a power of two, n & (n - 1) != 0 because the highest bit of (n - 1) must be 1(except n = 1)
 * 5. thus, if n & (n - 1) == 0, n is a power of two
*/
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return n >= 1 && !(n & (n - 1));
    }
};


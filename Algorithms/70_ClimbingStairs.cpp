// dynamic programming, dp[i] = dp[i - 1] + dp[i - 2] while dp[i] stands for 
// the distinct ways climbing to the i-th stair
class Solution {
public:
    int climbStairs(int n)
    {
        if(n <= 2)
            return n;
        int prev1 = 1;
        int prev2 = 2;
        for(int i = 3; i <= n; ++i)
        {
            int tmp = prev1 + prev2;
            prev1 = prev2;
            prev2 = tmp;
        }
        return prev2;
    }
};

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        int sum = 0;
        int y = x;
        while(y)
        {
            sum = sum * 10 + y % 10;
            y /= 10;
        }
        return sum == x;
    }
};

class Solution {
public:
    bool isHappy(int n) 
    {
        // record its cycle
        map<int, bool> m;
        while(1)
        {
            if(m[n])
                return false;
            m[n] = true;
            n = square(n);
            if(n == 1)
                return true;
        }
        return false;
    }
    
    int square(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};

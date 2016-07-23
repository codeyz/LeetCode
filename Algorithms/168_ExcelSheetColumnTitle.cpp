class Solution {
public:
    string convertToTitle(int n) 
    {
        if(!n)
            return string();
        if(n <= 26)
            return string(1, 'A' + n - 1);
        char c;
        if(n % 26 == 0)
            c = 'Z';
        else
            c = 'A' + n % 26 - 1;
        return convertToTitle(--n / 26) + string(1, c);
    }
};

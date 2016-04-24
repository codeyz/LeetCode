class Solution {
public:
    bool isPalindrome(string s) 
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            while(i < j && !isalpha(s[i]) && !isdigit(s[i]))
                ++i;
            while(i < j && !isalpha(s[j]) && !isdigit(s[j]))
                --j;
            if(i == j)
                return true;
            if(isalpha(s[i]) && isalpha(s[j]) && toupper(s[i]) != toupper(s[j]))
                return false;
            if(isdigit(s[i]) && isdigit(s[j]) && s[i] != s[j])
                return false;
            if((isdigit(s[i]) && isalpha(s[j])) || (isalpha(s[i]) && isdigit(s[j])))
                return false;
            ++i, --j;
        }
        return true;
    }
};

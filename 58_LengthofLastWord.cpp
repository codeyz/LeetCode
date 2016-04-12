class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int sum = 0;
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ')
            --i;
        while(i >= 0 && s[i] != ' ')
        {
            ++sum;
            --i;
        }
        return sum;
    }
};

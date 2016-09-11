class Solution {
public:
    int firstUniqChar(string s) {
        int num[26];
        memset(num, 0, 26 * sizeof(int));
        for(unsigned i = 0;i < s.size(); ++i)
        {
            ++num[s[i] - 'a'];
        }
        for(unsigned i = 0;i < s.size(); ++i)
        {
            if(num[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

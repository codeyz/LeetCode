class Solution {
public:
    char findTheDifference(string s, string t) {
        int t_num[26], s_num[26];
        cal(t_num, t);
        cal(s_num, s);
        for(int i = 0;i < 26; ++i)
        {
            if(t_num[i] != s_num[i])
                return 'a' + i;
        }
        return 'a';
    }
    
    void cal(int* num, const string& s)
    {
        memset(num, 0, 26 * sizeof(int));
        for(unsigned i = 0;i < s.size(); ++i)
        {
            ++num[s[i] - 'a'];
        }
    }
};

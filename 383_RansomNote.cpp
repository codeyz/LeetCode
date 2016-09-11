class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r_num[NUM_OF_LETTERS], m_num[NUM_OF_LETTERS];
        cal(r_num, ransomNote);
        cal(m_num, magazine);
        for(int i = 0;i < NUM_OF_LETTERS; ++i)
            if(m_num[i] < r_num[i])
                return false;
        return true;
    }
    
    void cal(int* num, const string& s)
    {
        memset(num, 0, NUM_OF_LETTERS * sizeof(int));
        for(unsigned i = 0;i < s.size(); ++i)
        {
            ++num[s[i] - 'a'];
        }
    }

private:
    const int NUM_OF_LETTERS = 26;
};

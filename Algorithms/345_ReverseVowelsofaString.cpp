class Solution {
public:
    string reverseVowels(string s) {
        int i, j;
        i = 0, j = s.size() - 1;
        while(i < j)
        {
            while(i < j && !vowel(s[i]))
                ++i;
            while(i < j && !vowel(s[j]))
                --j;
            swap(s[i], s[j]);
            ++i, --j;
        }
        return s;
    }
    
    bool vowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

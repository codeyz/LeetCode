class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        map<char, char> hash1, hash2;
        for(size_t i = 0;i < s.size(); ++i)
        {
            if(!hash1.count(s[i]))
            {
                if(hash2.count(t[i]))
                    return false;
                hash1[s[i]] = t[i];
                hash2[t[i]] = s[i];
            }
            else if(hash1[s[i]] != t[i])
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        vector<string> words = split(str);
        if(words.size() != pattern.size())
            return false;
        map<string, char> hash1;
        map<char, string> hash2;
        for(size_t i = 0;i < words.size(); ++i)
        {
            if(!hash1.count(words[i]))
            {
                if(hash2.count(pattern[i]))
                    return false;
                hash1[words[i]] = pattern[i];
                hash2[pattern[i]] = words[i];
            }
            else if(hash1[words[i]] != pattern[i])
                return false;
        }
        return true;
    }
    
    vector<string> split(string str)
    {
        vector<string> res;
        size_t pos, next;
        next = str.find(' ');
        pos = 0;
        while(next != string::npos)
        {
            res.push_back(str.substr(pos, next - pos));
            pos = next + 1;
            next = str.find(' ', pos);
        }
        res.push_back(str.substr(pos));
        return res;
    }
};

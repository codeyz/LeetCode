class Solution {
public:
    string countAndSay(int n) 
    {
        if(n < 1)
            return string();
        string res("1");
        for(int i = 2;i <= n; ++i)
            res = countAndSay(res);
        return res;
    }
    
    string countAndSay(string str)
    {
        string res;
        size_t i = 0;
        while(i < str.size())
        {
            size_t j = i;
            while(j < str.size() && str[i] == str[j])
                ++j;
            size_t sum = j - i;
            res += to_string(sum);
            res.push_back(str[i]);
            i = j;
        }
        return res;
    }
};

class Solution {
public:
    bool isValid(string s) 
    {
        stack<int> tmp;
        for(size_t i = 0;i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                tmp.push(s[i]);
            else if(tmp.empty())
                return false;
            else
            {
                if(s[i] == ')' && tmp.top() != '(')
                    return false;
                if(s[i] == ']' && tmp.top() != '[')
                    return false;
                if(s[i] == '}' && tmp.top() != '{')
                    return false;
                tmp.pop();
            }
        }
        return tmp.empty();
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int> > res;
        for(int i = 0;i < numRows; ++i)
        {
            vector<int> tmp(1, 1);
            if(i)
            {
                for(int j = 1; j < i; ++j)
                    tmp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                tmp.push_back(1);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
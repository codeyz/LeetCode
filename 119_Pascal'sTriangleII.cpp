class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> res(rowIndex + 1, 0);
        for(int i = 0; i <= rowIndex; ++i)
        {
            if(!i)
                res[0] = 1;
            else
            {
                int prev = res[0];
                for(int j = 1; j < i; ++j)
                {
                    int tmp = res[j];
                    res[j] += prev;
                    prev = tmp;
                }
                res[i] = 1;
            }
        }
        return res;
    }
};

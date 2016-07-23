class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(++num, 0);
        if(num >= 2)
            result[1] = 1;
        for(int i = 2; i < num; i *= 2)
        {
            for(int j = 0; j < i && i + j < num; j++)
                result[i +j] = result[j] + 1;
        }
        return result;
    }
};

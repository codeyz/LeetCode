class Solution {
public:
    string getHint(string secret, string guess) 
    {
        vector<int> bull(10, 0), cow(10, 0), bullAndcow(10, 0);
        for(size_t i = 0; i < secret.size(); ++i)
        {
            if(secret[i] == guess[i])
                ++bullAndcow[secret[i] - '0'];
            ++bull[secret[i] - '0'];
            ++cow[guess[i] - '0'];
        }
        int numOfbull, numOfcow, numOfbullAndcow;
        numOfbull = numOfcow = numOfbullAndcow = 0;
        for(size_t i = 0;i < bull.size(); ++i)
        {
            numOfbull += min(bull[i], cow[i]);
            numOfbullAndcow += bullAndcow[i];
        }
        numOfcow = numOfbull - numOfbullAndcow;
        return to_string(numOfbullAndcow) + "A" + to_string(numOfcow) + "B";
    }
};

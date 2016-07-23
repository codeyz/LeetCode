class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> res;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            int tmp = carry + digits[i];
            carry = tmp / 10;
            res.insert(res.begin(), tmp % 10);
        }
        if(carry)
            res.insert(res.begin(), carry);
        return res;
    }
};

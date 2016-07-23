class Solution {
public:
    string addBinary(string a, string b) 
    {
        int carry = 0;
        string res;
        int i, j;
        i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 && j >= 0)
        {
            int sum = (a[i--] - '0') + (b[j--] - '0') + carry;
            carry = sum / 2;
            res.insert(0, 1, sum % 2 + '0');
        }
        
        while(i >= 0)
        {
            int sum = (a[i--] - '0') + carry;
            carry = sum / 2;
            res.insert(0, 1, sum % 2 + '0');
        }
        
        while(j >= 0)
        {
            int sum = (b[j--] - '0') + carry;
            carry = sum / 2;
            res.insert(0, 1, sum % 2 + '0');
        }
        if(carry)
            res.insert(0, 1, carry + '0');
        return res;
    }
};

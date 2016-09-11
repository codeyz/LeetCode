class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for(unsigned i = 0;i < nums.size(); ++i)
            num ^= nums[i];
        return num;
    }
};

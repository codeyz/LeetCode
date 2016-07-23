class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, bool> hash;
        for(size_t i = 0;i < nums.size(); ++i)
        {
            if(hash[nums[i]])
                return true;
            hash[nums[i]] = true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        map<int, size_t> hash;
        for(size_t i = 0;i < nums.size(); ++i)
            if(!hash.count(nums[i]))
                hash[nums[i]] = i;
            else
            {
                if(i - hash[nums[i]] <= k)
                    return true;
                hash[nums[i]] = i;
            }
        return false;
    }
};

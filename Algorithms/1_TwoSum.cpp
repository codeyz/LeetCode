class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> hash;
        for(size_t i = 0;i < nums.size(); ++i)
        {
            if(hash.count(target - nums[i]))
            {
                vector<int> res(2, 0);
                res[0] = hash[target - nums[i]];
                res[1] = i;
                return res;
            }
            hash[nums[i]] = i;
        }
        return vector<int>();
    }
};

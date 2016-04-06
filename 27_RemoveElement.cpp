class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        size_t posOfVal, posOfOthers;
        posOfVal = posOfOthers = 0;
        
        // find first val
        while(posOfVal < nums.size() && nums[posOfVal] != val)
            ++posOfVal;
        
        while(1)
        {
            posOfOthers = posOfVal;
            while(posOfOthers < nums.size() && nums[posOfOthers] == val)
                ++posOfOthers;
            if(posOfOthers == nums.size())
                break;
            swap(nums[posOfVal], nums[posOfOthers]);
            ++posOfVal;
        }
        return posOfVal;
    }
};

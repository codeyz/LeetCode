class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        size_t posOfNewArray, i;
        i = posOfNewArray = 0;
        while(i < nums.size())
        {
            nums[posOfNewArray++] = nums[i];
            size_t j = i;
            while(j < nums.size() && nums[j] == nums[i])
                ++j;
            i = j;
        }
        return posOfNewArray;
    }
};

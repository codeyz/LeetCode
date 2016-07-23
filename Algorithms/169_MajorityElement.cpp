class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Boyer-Moore majority vote algorithm https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
        int counter = 0, candidate = 0;
        for(size_t i = 0;i < nums.size(); ++i)
        {
            if(!counter)
            {
                ++counter;
                candidate = nums[i];
            }
            else if(candidate == nums[i])
            {
                ++counter;
            }
            else
            {
                --counter;
            }
        }
        return candidate;
    }
};

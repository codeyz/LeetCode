class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        /*
        * two-points:
        * positionOfZero points to the position of 0
        * positionOfNonZero points to the first position of non-0 at the right of positionOfZero
        * Every time swap the numbers and update the pointers
        */
        positionOfZero = positionOfNonZero = 0;
        // find the first 0
        while(positionOfZero < nums.size() && nums[positionOfZero])
            ++positionOfZero;
        // find the fist non-0 at the right of the first 0
		positionOfNonZero = positionOfZero + 1;
		update(nums);
        while(positionOfNonZero < nums.size())
        {
            nums[positionOfZero] = nums[positionOfNonZero];
            nums[positionOfNonZero] = 0;
            update(nums);
        }
    }
    
    void update(vector<int>& nums)
    {
        // find next 0
        while(positionOfZero < nums.size() && nums[positionOfZero])
            ++positionOfZero;
        // find next non-0
        while(positionOfNonZero < nums.size() && !nums[positionOfNonZero])
            ++positionOfNonZero;
    }
    
private:
    size_t positionOfZero;
    size_t positionOfNonZero;
};


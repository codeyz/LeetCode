/* Approach 1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> tmp(nums1);
        nums1.clear();
        int i, j;
        i = j = 0;
        while(i < m && j < n)
        {
            if(tmp[i] <= nums2[j])
                nums1.push_back(tmp[i++]);
            else
                nums1.push_back(nums2[j++]);
        }
        while(i < m)  
            nums1.push_back(tmp[i++]);
        while(j < n)
            nums1.push_back(nums2[j++]);
    }
};
*/

// Approach 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i, j, k;
        i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while(j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};

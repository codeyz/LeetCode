class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int, int> hash;
        for(size_t i = 0;i < nums1.size(); ++i)
            ++hash[nums1[i]];
        vector<int> result;
        for(size_t i = 0;i < nums2.size(); ++i)
            if(hash[nums2[i]] > 0)
            {
                result.push_back(nums2[i]);
                --hash[nums2[i]];
            }
        return result;
    }
};

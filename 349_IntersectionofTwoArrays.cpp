/* hash
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> hash;
        for(size_t i = 0;i < nums1.size(); ++i)
            hash[nums1[i]] = 1;
        vector<int> result;
        for(size_t i = 0;i < nums2.size(); ++i)
            if(hash[nums2[i]])
            {
                hash[nums2[i]] = 0;
                result.push_back(nums2[i]);
            }
        return result;
    }
};
*/

/* binary search
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        for(int i = 0;i < nums2.size();)
        {
            if(binarySearch(nums1, nums2[i]) != -1)
            {
                result.push_back(nums2[i]);
            }
            int j = i + 1;
            while(nums2[j] == nums2[i])
                ++j;
            i = j;
        }
        return result;
    }
    
    int binarySearch(const vector<int>& nums, int x)
    {
        int low, high, mid;
        low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            mid = high - (high - low) / 2;
            if(nums[mid] == x)
                return mid;
            if(nums[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
*/

// two pointers
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i, j;
        i = j = 0;
        vector<int> result;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
                ++i;
            else if(nums1[i] > nums2[j])
                ++j;
            else
            {
                result.push_back(nums1[i]);
                while(i < nums1.size() && nums1[i] == nums2[j])
                    ++i;
            }
        }
        return result;
    }
};

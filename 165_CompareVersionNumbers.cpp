class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i, j;
        i = j = 0;
        while(i < version1.size() && j < version2.size())
        {
            int r1, r2;
            r1 = r2 = 0;
            while(i < version1.size() && version1[i] != '.')
                r1 = r1 * 10 + (version1[i++] - '0');
            while(j < version2.size() && version2[j] != '.')
                r2 = r2 * 10 + (version2[j++] - '0');
            if(r1 < r2)
                return -1;
            if(r1 > r2)
                return 1;
            ++i, ++j;
        }
        if(i < version1.size())
        {
            while(i < version1.size())
            {
                if(version1[i] != '.' && version1[i] != '0')
                    return 1;
                ++i;
            }
            return 0;
        }
        if(j < version2.size())
        {
            while(j < version2.size())
            {
                if(version2[j] != '.' && version2[j] != '0')
                    return -1;
                ++j;
            }
            return 0;
        }
        return 0;
    }
};

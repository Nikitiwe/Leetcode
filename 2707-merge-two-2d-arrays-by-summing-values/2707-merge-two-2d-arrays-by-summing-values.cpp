class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int l=0, r=0;
        while (l<nums1.size()||r<nums2.size())
        {
            if (l<nums1.size()&&r<nums2.size())
            {
                if (nums1[l][0]==nums2[r][0])
                {
                    ans.push_back({nums1[l][0], nums1[l][1]+nums2[r][1]});
                    l++;
                    r++;
                }
                else if (nums1[l][0]<nums2[r][0])
                {
                    ans.push_back({nums1[l][0], nums1[l][1]});
                    l++;
                }
                else
                {
                    ans.push_back({nums2[r][0], nums2[r][1]});
                    r++;
                }
            }
            else if (l<nums1.size())
            {
                while (l<nums1.size())
                {
                    ans.push_back({nums1[l][0], nums1[l][1]});
                    l++;
                }
            }
            else
            {
                while (r<nums2.size())
                {
                    ans.push_back({nums2[r][0], nums2[r][1]});
                    r++;
                }
            }
        }
        return ans;
    }
};
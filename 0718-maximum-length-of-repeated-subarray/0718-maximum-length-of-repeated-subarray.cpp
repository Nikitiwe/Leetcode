class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for (int i=0; i!=nums1.size(); i++)
        {
            int c=0;
            for (int j=0; j!=nums2.size(); j++)
            {
                if (i+j<nums1.size()&&nums2[j]==nums1[j+i]) c++;
                else c=0;
                ans=max(ans, c);
            }
        }
        for (int i=0; i!=nums2.size(); i++)
        {
            int c=0;
            for (int j=0; j!=nums1.size(); j++)
            {
                if (i+j<nums2.size()&&nums1[j]==nums2[j+i]) c++;
                else c=0;
                ans=max(ans, c);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l1=0, l2=0, ans=0;
        while (l2<nums2.size()&&l1<nums1.size())
        {
            if (nums1[l1]<=nums2[l2])
            {
                ans=max(ans, l2-l1);
                l2++;
            }
            else l1++;
        }
        return ans;
    }
};
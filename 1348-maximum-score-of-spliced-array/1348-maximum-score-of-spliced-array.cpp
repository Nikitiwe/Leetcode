class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int s1=0, s2=0;
        for (int i=0; i!=nums1.size(); i++)
        {
            s1+=nums1[i];
            s2+=nums2[i];
        }
        int d=0, ans=max(s1, s2);
        for (int i=0; i!=nums1.size(); i++)
        {
            d+=nums2[i]-nums1[i];
            if (d<0) d=0;
            else ans=max(ans, s1+d);
        }
        d=0;
        for (int i=0; i!=nums1.size(); i++)
        {
            d+=nums1[i]-nums2[i];
            if (d<0) d=0;
            else ans=max(ans, s2+d);
        }
        return ans;
    }
};
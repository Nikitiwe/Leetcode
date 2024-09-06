class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long a=0, b=0, z1=0, z2=0;
        for (int i=0; i!=nums1.size(); i++)
        {
            if (nums1[i]==0) z1++;
            else a+=nums1[i];
        }
        for (int i=0; i!=nums2.size(); i++)
        {
            if (nums2[i]==0) z2++;
            else b+=nums2[i];
        }
        if ((a<b+z2&&z1==0)||(a+z1>b&&z2==0)) return -1;
        return max(a+z1, b+z2);
    }
};
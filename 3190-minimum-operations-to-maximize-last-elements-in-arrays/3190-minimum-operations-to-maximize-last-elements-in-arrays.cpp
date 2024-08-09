class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int bad11=0, bad12=0, bad21=0, bad22=0, n=nums1.size()-1;
        for (int i=0; i<n; i++)
        {
            if (nums1[i]>nums1[n]) if (nums2[i]>nums1[n]||nums1[i]>nums2[n]) return -1;
            if (nums2[i]>nums2[n]) if (nums1[i]>nums2[n]||nums2[i]>nums1[n]) return -1;
            if (nums1[i]>nums1[n]) bad11++;
            if (nums1[i]>nums2[n]) bad12++;
            if (nums2[i]>nums1[n]) bad21++;
            if (nums2[i]>nums2[n]) bad22++;
        }
    return min(bad22+bad11, 1+bad21+bad12);
    }
};
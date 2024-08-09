class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int bad11=0, bad12=0, bad21=0, bad22=0, n=nums1.size()-1, temp;
        for (int i=0; i<n; i++)
        {
            temp=0;
            if (nums1[i]>nums1[n]) {bad11++; temp++;}
            if (nums2[i]>nums2[n]) {bad22++; temp++;}
            if (nums1[i]>nums2[n]) {bad12++; temp++;}
            if (nums2[i]>nums1[n]) {bad21++; temp++;}
            if (temp>1) return -1;
        }
    return min(bad22+bad11, 1+bad21+bad12);
    }
};
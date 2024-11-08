class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        for (int i=1; i<=9; i++)
        {
            if (find(nums1.begin(), nums1.end(), i)!=nums1.end()&&find(nums2.begin(), nums2.end(), i)!=nums2.end()) return i;
        }
        int a=*min_element(nums1.begin(), nums1.end()), b=*min_element(nums2.begin(), nums2.end());
        if (a<b) return 10*a+b;
        else return 10*b+a;
    }
};
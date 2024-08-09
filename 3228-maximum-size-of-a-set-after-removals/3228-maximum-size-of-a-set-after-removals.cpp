class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m, m1, m2;
        int ans1, ans2, n=nums1.size();
        for (int i=0; i!=n; i++)
        {
            m1.insert(nums1[i]);
            m2.insert(nums2[i]);
            m.insert(nums1[i]);
            m.insert(nums2[i]);
        }
        ans1=min((int)m.size()-(int)m2.size(), n/2);
        ans2=min((int)m.size()-(int)m1.size(), n/2);
        return min(ans1+ans2+((int)m1.size()+(int)m2.size()-(int)m.size()), n);
    }
};
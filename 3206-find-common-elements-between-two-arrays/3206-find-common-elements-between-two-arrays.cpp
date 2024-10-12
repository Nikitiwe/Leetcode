class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a, b;
        for (int i=0; i!=nums1.size(); i++) a.insert(nums1[i]);
        for (int i=0; i!=nums2.size(); i++) b.insert(nums2[i]);
        int x=0, y=0;
        for (int i=0; i!=nums1.size(); i++) if (b.count(nums1[i])>0) x++;
        for (int i=0; i!=nums2.size(); i++) if (a.count(nums2[i])>0) y++;
        return {x, y};
    }
};
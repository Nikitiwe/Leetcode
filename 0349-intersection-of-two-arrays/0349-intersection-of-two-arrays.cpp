class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m, n;
        vector<int> ans;
        for (int i=0; i!=nums1.size(); i++)
        {
            m.insert(nums1[i]);
        }
        for (int i=0; i!=nums2.size(); i++)
        {
            n.insert(nums2[i]);
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (n.count(*it) > 0) ans.push_back(*it);
        }
        return ans;
    }
};
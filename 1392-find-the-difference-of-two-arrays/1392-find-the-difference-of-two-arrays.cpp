class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_set<int> f, s;
        for (int i=0; i!=nums1.size(); i++) f.insert(nums1[i]);
        for (int i=0; i!=nums2.size(); i++) s.insert(nums2[i]);
        vector<int> t;
        for (auto i=f.begin(); i!=f.end(); i++)
        {
            if (s.count(*i)==0) t.push_back(*i);
        }
        ans.push_back(t);
        t.clear();
        for (auto i=s.begin(); i!=s.end(); i++)
        {
            if (f.count(*i)==0) t.push_back(*i);
        }
        ans.push_back(t);
        return ans;
    }
};
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s;
        for (int i=0; i!=nums.size(); i++) s.insert(nums[i]);
        vector<int> ans;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            ans.push_back(*it);
        }
        vector<int> a;
        for (int i=ans.size()-1; i>=0; i--)
        {
            a.push_back(ans[i]);
            if (a.size() == k) break;
        }
        return a;
    }
};
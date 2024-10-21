class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> m;
        vector<int> ans;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=m.size();
            m.insert(nums[i]);
            if (m.size()==t) ans.push_back(nums[i]);
        }
        return ans;
    }
};
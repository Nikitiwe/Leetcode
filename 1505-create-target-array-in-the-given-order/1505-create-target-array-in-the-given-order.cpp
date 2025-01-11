class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& id) {
        vector<int> ans;
        for (int i=0; i!=nums.size(); i++)
        {
            ans.insert(ans.begin()+id[i], nums[i]);
        }
        return ans;
    }
};
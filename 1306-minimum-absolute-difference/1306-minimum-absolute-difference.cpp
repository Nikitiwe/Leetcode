class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int d=2000001;
        for (int i=0; i<nums.size()-1; i++) d=min(d, nums[i+1]-nums[i]);
        vector<vector<int>> ans;
        for (int i=0; i<nums.size()-1; i++)
        {
            if (nums[i+1]-nums[i]==d) ans.push_back({nums[i], nums[i+1]});
        }
        return ans;
    }
};
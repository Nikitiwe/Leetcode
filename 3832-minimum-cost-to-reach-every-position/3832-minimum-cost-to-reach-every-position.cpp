class Solution {
public:
    vector<int> minCosts(vector<int>& nums) {
        vector<int> ans = nums;
        int mi = ans[0];
        for (int i=1; i<ans.size(); i++)
        {
            mi = min(mi, ans[i]);
            ans[i] = mi;
        }
        return ans;
    }
};
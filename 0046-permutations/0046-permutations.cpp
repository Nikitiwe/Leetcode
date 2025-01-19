class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size(), k=n;
        k--;
        while (k>0)
        {
            n*=k;
            k--;
        }
        for (int i=0; i<n; i++)
        {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> ans(q.size(), 0), arr(nums.size()+1, 0);
        int t = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            t ^= nums[i];
            arr[i+1] = t;
        }
        for (int i=0; i!=q.size(); i++)
        {
            ans[i] = arr[q[i][1]+1] ^ arr[q[i][0]];
        }
        return ans;
    }
};
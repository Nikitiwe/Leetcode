class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        long ans = 0, mod = 1e9 + 7;
        for (int i=0; i!=q.size(); i++)
        {
            int id = q[i][0];
            int r = q[i][1];
            int k = q[i][2];
            int v = q[i][3];
            for (int j=id; j<=r; j+=k)
            {
                nums[j] = ((long)nums[j]*v) % mod;
            }
        }
        for (int i=0; i!=nums.size(); i++) ans ^= nums[i];
        return ans;
    }
};
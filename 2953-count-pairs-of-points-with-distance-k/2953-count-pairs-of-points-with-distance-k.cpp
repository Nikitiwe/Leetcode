class Solution {
public:
    int countPairs(vector<vector<int>>& nums, int k) {
        unordered_map<long, int> m;
        long mn = 1e7;
        for (int i=0; i!=nums.size(); i++) m[mn*nums[i][0] + nums[i][1]]++;
        int ans = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            int a = nums[i][0];
            int b = nums[i][1];
            m[mn*a + b]--;
            for (int j=0; j<=k; j++)
            {
                ans += m[mn*(a^j) + b^(k-j)];
                //if (mn*(a^j) + b^(k-j) == mn*a + b) ans--;
            }
        }
        return ans;
    }
};
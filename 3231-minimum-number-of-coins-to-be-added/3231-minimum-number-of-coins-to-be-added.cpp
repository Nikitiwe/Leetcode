class Solution {
public:
    int minimumAddedCoins(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int t = 1;
        int r = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (r >= k) break;
            while (t < nums[i])
            {
                ans++;
                r += t;
                t *= 2;
            }
            r += nums[i];
            t = r + 1;
        }
        while (r < k)
        {
            ans++;
            r += t;
            t = r + 1;
        }
        return ans;
    }
};
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        vector<vector<long>> arr(nums.size(), vector<long>(k+1, 0));
        // количество чисел в последовательности + сумма, храним число таких хуевин
        for (int i=0; i<1; i++) if (nums[i] <= k) arr[0][nums[i]]++;
        long ans = 0, st = 1, mod = 1e9 + 7;
        for (int i=1; i<nums.size(); i++)
        {
            for (int c=i; c>=1; c--)
            {
                for (int j=0; j<=k; j++)
                {
                    if (arr[c-1][j] > 0 && j + nums[i] <= k)
                    {
                        arr[c][j + nums[i]] += arr[c-1][j];
                        arr[c][j + nums[i]] %= mod;
                    }
                }
            }
            if (nums[i] <= k) arr[0][nums[i]]++;
        }
        for (int i=nums.size()-1; i>=0; i--)
        {
            ans += arr[i][k] * st;
            ans %= mod;
            st *= 2;
            st %= mod;
        }
        return ans;
    }
};
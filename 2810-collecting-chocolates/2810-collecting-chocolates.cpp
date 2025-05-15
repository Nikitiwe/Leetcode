class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> arr(n, vector<long long>(n, 0));
        long long ans = 1e13, sum = 0;
        for (int i=0; i!=n; i++)
        {
            arr[i][0] = nums[i];
            sum += arr[i][0];
        }
        ans = min(ans, sum);
        for (long long k=1; k<n; k++)
        {
            sum = k * x;
            for (int i=0; i!=n; i++)
            {
                arr[i][k] = min((long long)nums[(i+k) % n], arr[i][(k-1+n)%n]);
                sum += arr[i][k];
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};
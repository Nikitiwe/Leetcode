class Solution {
public:
    long long minCost(int n, vector<vector<int>>& nums) {
        vector<vector<long long>> arr(n/2, vector<long long>(6, 1000000000000000));
        for (int i=0; i<n/2; i++) // 01 02 10 12 20 21
        {
            if (i == 0)
            {
                arr[i][0] = nums[i][0] + nums[n-1-i][1];
                arr[i][1] = nums[i][0] + nums[n-1-i][2];
                arr[i][2] = nums[i][1] + nums[n-1-i][0];
                arr[i][3] = nums[i][1] + nums[n-1-i][2];
                arr[i][4] = nums[i][2] + nums[n-1-i][0];
                arr[i][5] = nums[i][2] + nums[n-1-i][1];
            }
            else
            {
                arr[i][0] = min({arr[i-1][2], arr[i-1][3], arr[i-1][4]});
                arr[i][1] = min({arr[i-1][2], arr[i-1][4], arr[i-1][5]});
                arr[i][2] = min({arr[i-1][0], arr[i-1][1], arr[i-1][5]});
                arr[i][3] = min({arr[i-1][0], arr[i-1][4], arr[i-1][5]});
                arr[i][4] = min({arr[i-1][0], arr[i-1][1], arr[i-1][3]});
                arr[i][5] = min({arr[i-1][1], arr[i-1][2], arr[i-1][3]});
                
                arr[i][0] += nums[i][0] + nums[n-1-i][1];
                arr[i][1] += nums[i][0] + nums[n-1-i][2];
                arr[i][2] += nums[i][1] + nums[n-1-i][0];
                arr[i][3] += nums[i][1] + nums[n-1-i][2];
                arr[i][4] += nums[i][2] + nums[n-1-i][0];
                arr[i][5] += nums[i][2] + nums[n-1-i][1];
            }
        }
        long long ans = 1000000000000000;
        for (int j=0; j<6; j++) ans = min(ans, arr[n/2-1][j]);
        return ans;
    }
};
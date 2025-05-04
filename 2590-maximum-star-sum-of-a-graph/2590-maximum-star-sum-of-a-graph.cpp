class Solution {
public:
    int maxStarSum(vector<int>& nums, vector<vector<int>>& e, int k) {
        int ans = -2000000000;
        vector<vector<int>> arr(nums.size(), vector<int>());
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back(nums[e[i][1]]);
            arr[e[i][1]].push_back(nums[e[i][0]]);
        }
        for (int i=0; i!=arr.size(); i++)
        {
            int sum = nums[i];
            sort(arr[i].rbegin(), arr[i].rend());
            for (int j=0; j<min((int)arr[i].size(), k); j++)
            {
                if (arr[i][j] >= 0) sum += arr[i][j];
                else break;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
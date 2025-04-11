class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        vector<int> ans(nums.size()+1, 0);
        ans[1] = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            int t = 0;
            for (int j = 0; j<k; j++) // это сдвиг на j индексов для определения начала текущего интервала
            {
                if (i-j >= 0) for (int d = 0; d<=j; d++) // это сдвиг на d индексов для определения главного числа текущего интервала
                {
                    //arr[j][d] = ans[i-j] + nums[i-d]*(j+1);
                    t = max(t, ans[i-j] + nums[i-d]*(j+1));
                }
            }
            ans[i+1] = t;
            //arr = zero;
        }
        return ans.back();
    }
};
class Solution {
public:
    int maxProfit(int kk, vector<int>& nums) {
        vector<int> ans(nums.size()+1, 0), prev=ans;
        for (int k=1; k<=kk; k++)
        {
            //if (k*2>nums.size()) break;
            int miid=0;
            for (int i=0; i<nums.size(); i++)
            {
                ans[i+1]=max(ans[i+1], prev[miid]+nums[i]-nums[miid]);
                if (prev[miid]-nums[miid]<=prev[i]-nums[i])
                {
                    miid=i;
                }
                ans[i+1]=max(ans[i+1], ans[i]);
            }
            prev=ans;
        }
        return ans.back();
        return *max_element(ans.begin(), ans.end());
    }
};
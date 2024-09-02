class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=0, ts=0, tc=0;
        unordered_map<int, int> ma;
        for (int i=0; i!=k; i++)
        {
            ma[nums[i]]++;
            ts+=nums[i];
            if (ma[nums[i]]==1) tc++;
        }
        if (tc>=m) ans=max(ans, ts);
        for (int i=k; i<nums.size(); i++)
        {
            ma[nums[i]]++;
            if (ma[nums[i]]==1) tc++;
            if (ma[nums[i-k]]==1) tc--;
            ma[nums[i-k]]--;
            ts+=nums[i];
            ts-=nums[i-k];
            if (tc>=m) ans=max(ans, ts);
        }
        return ans;
    }
};
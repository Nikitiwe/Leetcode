class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int t = k*threshold;
        int sum = 0;
        for (int i=0; i!=k; i++) sum += nums[i];
        int ans = 0;
        if (sum >= t) ans++;
        for (int i=k; i<nums.size(); i++)
        {
            sum += nums[i];
            sum -= nums[i-k];
            if (sum >= t) ans++;
        }
        return ans;
    }
};
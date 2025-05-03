class Solution {
public:
    int findMinMoves(vector<int>& nums) {
        int k = 0;
        for (int i=0; i!=nums.size(); i++) k += nums[i];
        if (k % nums.size() != 0) return -1;
        k /= nums.size();
        int ans = 0;
        int kk = k;
        vector<int> r(nums.size(), 0);
        int sum = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum += nums[i];
            if (sum > k) r[i] = sum - k;
            k += kk;
        }
        sum = 0;
        k = kk;
        for (int i=nums.size()-1; i>=0; i--)
        {
            sum += nums[i];
            if (sum > k) r[i] += sum - k;
            ans = max(ans, r[i]);
            k += kk;
        }
        return ans;
    }
};
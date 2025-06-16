class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        vector<int> r(nums.size(), 0);
        vector<long> arr(1e5 + 1, 0), l = arr;
        for (int i=nums.size()-1; i >= 0; i--)
        {
            if (2*nums[i] <= 1e5) r[i] = arr[2*nums[i]];
            arr[nums[i]]++;
        }
        long ans = 0, mod = 1e9 + 7;
        for (int i=0; i != nums.size(); i++)
        {
            if (2*nums[i] <= 1e5)
            {
                ans += l[2*nums[i]] * r[i];
                ans %= mod;
            }
            l[nums[i]]++;
        }
        return ans;
    }
};
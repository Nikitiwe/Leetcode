class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> u(nums.size(), 0), d(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) u[i]=(long long)nums[i];
        for (int i=1; i<nums.size(); i++)
        {
            u[i]=max({u[i-1], u[i], d[i-1]+nums[i]});
            d[i]=max({d[i-1], d[i], u[i-1]-nums[i]});
        }
        return max(u.back(), d.back());
    }
};
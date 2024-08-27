class Solution {
public:
    long long numberOfWeeks(vector<int>& nums) {
        long long ans=0;
        int m=0;
        for (int i=0; i!=nums.size(); i++)
        {
            ans+=nums[i];
            m=max(m, nums[i]);
        }
        return min(ans, (long long)(ans-m)*2+1);
    }
};
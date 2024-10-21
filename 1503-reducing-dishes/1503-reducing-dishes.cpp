class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(), nums.end());
        for (int k=0; k<=nums.size()-1; k++)
        {
            int sum=0;
            for (int i=0; i+k<nums.size(); i++)
            {
                sum+=nums[i+k]*(i+1);
            }
            ans=max(ans, sum);
        }
        return ans;
    }
};
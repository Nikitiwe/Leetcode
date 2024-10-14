class Solution {
public:
    int maxIncreasingGroups(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long temp=0;
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]>=ans+1)
            {
                ans++;
                temp+=nums[i]-ans;
            }
            else
            {
                temp+=nums[i];
                if (temp>=ans+1)
                {
                    ans++;
                    temp-=ans;
                }
            }
        }
        return ans;
    }
};
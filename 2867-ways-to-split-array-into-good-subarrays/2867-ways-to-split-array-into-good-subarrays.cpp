class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        if (*max_element(nums.begin(), nums.end())==0) return 0;
        long ans=1;
        int i=0, t=1;
        while (nums[i]==0) i++;
        //if (i<nums.size()) ans=1;
        for (i; i<nums.size(); i++)
        {
            if (nums[i]==0) t++;
            else
            {
                ans*=t;
                ans%=1000000007;
                t=1;
            }
        }
        return ans;
    }
};
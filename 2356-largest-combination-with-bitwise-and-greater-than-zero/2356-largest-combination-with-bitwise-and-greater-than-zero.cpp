class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int ans=0, t=1;
        for (int k=1; k<=24; k++)
        {
            int c=0;
            t*=2;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i]%t>=(t/2)) c++;
            }
            ans=max(ans, c);
        }
        return ans;
    }
};
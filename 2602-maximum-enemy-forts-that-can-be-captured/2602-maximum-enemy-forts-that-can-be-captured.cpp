class Solution {
public:
    int captureForts(vector<int>& nums) {
        int ans=0, a=nums[0], c=0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]!=0)
            {
                if (nums[i]*a==-1)
                {
                    ans=max(ans, c);
                }
                a=nums[i];
                c=0;
            }
            else c++;
        }
        return ans;
    }
};
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=50;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=0;
            while (nums[i]>0)
            {
                t+=nums[i]%10;
                nums[i]/=10;
            }
            ans=min(ans, t);
        }
        return ans;
    }
};
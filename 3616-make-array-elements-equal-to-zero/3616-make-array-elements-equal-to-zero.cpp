class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0, ans=0, l=0;
        for (int i=0; i!=nums.size(); i++) sum+=nums[i];
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==0)
            {
                if (l==sum) ans+=2;
                else if (l+1==sum) ans++;
                else if (l==sum+1) ans++;
            }
            l+=nums[i];
            sum-=nums[i];
        }
        return ans;
    }
};
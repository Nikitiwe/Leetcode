class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int ans=0, i=0, n=nums.size();   
        while (1)
        {
            int a=i%n;
            if (nums[a]>0)
            {
                nums[a]--;
                ans++;
                if (a==k&&nums[a]==0) return ans;
            }
            i++;
        }
        return -1;
    }
};
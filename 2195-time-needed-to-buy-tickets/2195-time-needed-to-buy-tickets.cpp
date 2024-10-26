class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int ans=0, i=0, n=nums.size();   
        while (1)
        {
            if (nums[i%n]>0)
            {
                nums[i%n]--;
                ans++;
                if (i%n==k&&nums[i%n]==0) return ans;
            }
            i++;
        }
        return -1;
    }
};
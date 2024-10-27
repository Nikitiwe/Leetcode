class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0, t=0;
        for (int i=1; i<nums.size(); i++) sum+=nums[i];
        if (sum==0) return 0;
        for (int i=1; i<nums.size(); i++)
        {
            t+=nums[i-1];
            sum-=nums[i];
            if (t==sum) return i;
        }
        if (t==0) return nums.size()-1;
        return -1;
    }
};
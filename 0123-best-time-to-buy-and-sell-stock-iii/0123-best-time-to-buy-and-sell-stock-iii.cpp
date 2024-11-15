class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<int> arr(nums.size(), 0), ans=arr;
        int mi=nums[0], ma=0;
        for (int i=1; i<arr.size(); i++)
        {
            ma=max(ma, nums[i]);
            arr[i]=max(arr[i], ma-mi);
            if (nums[i]<mi)
            {
                ma=0;
                mi=nums[i];
            }
            arr[i]=max(arr[i-1], arr[i]);
        }
        if (arr.size()>2)
        {
            mi=nums[2]-arr[1]; ma=0;
            for (int i=3; i<arr.size(); i++)
            {
                ma=max(ma, nums[i]);
                ans[i]=max(ans[i], ma-mi);
                if (nums[i]-arr[i-1]<mi)
                {
                    ma=0;
                    mi=nums[i]-arr[i-1];
                }
                ans[i]=max(ans[i-1], ans[i]);
            }
        }
        return max(ans.back(), arr.back());
    }
};
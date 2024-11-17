class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int id=0;
        vector<int> ans;
        for (int i=0; i!=k; i++)
        {
            if (nums[i]>=nums[id]) id=i;
        }
        ans.push_back(nums[id]);
        for (int i=k; i<nums.size(); i++)
        {
            if (nums[i]>=nums[id]) id=i;
            if (id<=i-k)
            {
                id=i-k+1;
                for (int j=0; j!=k; j++)
                {
                    if (nums[i-k+1+j]>=nums[id]) id=i-k+1+j;
                }
            }
            ans.push_back(nums[id]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<bool> arr(nums.size(), 1);
        for (int i=0; i<k; i++) arr[i]=0;
        for (int i=nums.size()-1; i>=nums.size()-k; i--) arr[i]=0;
        if (k>1) {
        for (int i=0; i<nums.size()-k; i++)
        {
            if (nums[i]<nums[i+1])
            {
                for (int j=2; j<=k; j++)
                {
                    arr[i+j]=0;
                }
            }
        }
        for (int i=nums.size()-1; i>=k; i--)
        {
            if (nums[i-1]>nums[i])
            {
                for (int j=2; j<=k; j++)
                {
                    arr[i-j]=0;
                }
            }
        }
    }
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) if (arr[i]==1) ans.push_back(i);
        return ans;
    }
};
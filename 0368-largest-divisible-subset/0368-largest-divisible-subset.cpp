class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size()==1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> arr(nums.size(), 1);
        vector<int> m(nums.size(), -1);
        int t=0;
        for (int i=1; i<nums.size(); i++)
        {
            int ma=-1;
            for (int j=0; j<i; j++)
            {
                if (nums[i]%nums[j]==0) ma=max(ma, arr[j]);
            }
            if (ma>-1)
            {
                arr[i]=ma+1;
                /*if (t==-1) t=i;
                else*/ if (arr[i]>arr[t]) t=i;
                for (int j=0; j<i; j++)
                {
                    if (arr[j]==ma&&nums[i]%nums[j]==0)
                    {
                        m[i]=j;
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        while (t>=0)
        {
            ans.push_back(nums[t]);
            t=m[t];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
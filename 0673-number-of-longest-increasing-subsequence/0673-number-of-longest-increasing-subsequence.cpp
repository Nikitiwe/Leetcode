class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> arr(nums.size(), 1), l(nums.size(), 1);
        arr[0]=1;
        l[0]=1;
        for (int i=1; i<nums.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[i]>nums[j])
                {
                    if (l[i]<l[j]+1)
                    {
                        l[i]=l[j]+1;
                        arr[i]=arr[j];
                    }
                    else if (l[i]==l[j]+1)
                    {
                        arr[i]+=arr[j];
                    }
                }
            }
        }
        int ans=0, t=*max_element(l.begin(), l.end());
        for (int i=0; i!=nums.size(); i++) if (l[i]==t) ans+=arr[i];
        return ans;
        
    }
};
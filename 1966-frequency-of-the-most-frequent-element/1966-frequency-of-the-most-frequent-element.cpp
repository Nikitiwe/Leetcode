class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> d(nums.size(), 0);
        for (int i=nums.size()-1; i>0; i--)
        {
            d[i]=nums[i]-nums[i-1];
        }
        long l=0, r=0, temp=0, ans=1;
        while (r<nums.size())
        {
            if (temp<=k)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==nums.size()) break;
                temp+=(r-l)*d[r];
            }
            else
            {
                temp-=(nums[r]-nums[l]);
                l++;
            }
        }
        return ans;
    }
};
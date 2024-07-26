class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0, r, temp;
        if (nums.size()<3) return 0;
        for (int i=0; i<nums.size()-2; i++)
        {
            r=0;
            for (int j=i+1; j<nums.size()-1; j++)
            {
                temp=nums[i]+nums[j];
                for (int k=r; k<nums.size(); k++)
                {
                    if (k>j)
                    {
                        if (nums[k]<temp) r=k;
                        else break;
                    }
                }
                if (r-j>=0) ans+=r-j;
            }
        }
        return ans;
    }
};
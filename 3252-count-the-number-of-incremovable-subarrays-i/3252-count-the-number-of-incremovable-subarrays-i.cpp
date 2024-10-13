class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i; j<nums.size(); j++)
            {
                bool isit=1;
                for (int a=0; a<i-1; a++)
                {
                    if (nums[a]>=nums[a+1])
                    {
                        isit=0;
                        break;
                    }
                }
                if (i>0&&j<nums.size()-1&&nums[i-1]>=nums[j+1]) isit=0;
                for (int a=j+1; a<nums.size()-1; a++)
                {
                    if (nums[a]>=nums[a+1])
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) ans++;
            }
        }
        return ans;
    }
};
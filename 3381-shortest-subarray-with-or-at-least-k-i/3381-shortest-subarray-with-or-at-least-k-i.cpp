class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = nums.size() + 1;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i; j<nums.size(); j++)
            {
                if (j-i+1 < ans)
                {
                    int t = 0;
                    for (int a=i; a<=j; a++)
                    {
                        t |= nums[a];
                    }
                    if (t >= k) ans = min(ans, j-i+1);
                }
            }
        }
        if (ans < nums.size() + 1) return ans;
        else return -1;
    }
};
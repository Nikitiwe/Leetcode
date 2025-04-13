class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0, t = 1;
        for (int it=0; it!=31; it++)
        {
            int c = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                if ((nums[i] & t) == t) c++;
            }
            if (c >= k) ans |= t;
            t <<= 1;
        }
        return ans;
    }
};
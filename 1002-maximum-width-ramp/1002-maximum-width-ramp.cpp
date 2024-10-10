class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> l, lid;
        int m=60000;
        for (int i=0; i!=nums.size(); i++)
        {
            if (m>nums[i])
            {
                m=nums[i];
                l.push_back(m);
                lid.push_back(i);
            }
        }
        int r=l.size()-1, ans=0;
        for (int i=nums.size()-1; i>=0; i--)
        {
            while (r>=0&&nums[i]>=l[r])
            {
                ans=max(ans, i-lid[r]);
                r--;
            }
        }
        return ans;
    }
};
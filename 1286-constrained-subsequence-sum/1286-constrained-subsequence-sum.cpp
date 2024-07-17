class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        int temp, m, mid=-999999;
        for (int i=1; i!=nums.size(); i++)
        {
            temp=nums[i];
            m=temp;
            if (i-mid<=k) m=max(nums[i]+nums[mid], nums[i]);
            else for (int j=1; j<=k; j++)
            {
                if (i-j>=0)
                {
                    if (temp+nums[i-j]>m) {m=temp+nums[i-j]; mid=i-j;}
                }
            }
            nums[i]=m;
            if (mid!=-999999&&nums[i]>nums[mid]) {mid=i;}
        }
        return *max_element(nums.begin(), nums.end());
    }
}; // ладно, искать каждый раз максимум заново накладно
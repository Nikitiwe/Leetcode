class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        sum.push_back(nums[0]);
        for (int i=1; i!=nums.size(); i++)
        {
            if ((sum[sum.size()-1]>=0&&nums[i]>=0)||(sum[sum.size()-1]<0&&nums[i]<0))
            {
                sum[sum.size()-1]+=nums[i];
            }
            else sum.push_back(nums[i]);
        }
        int m=0, l=0, ans=0;
        if (sum.size()==1&&sum[0]<0)
        {
            return *max_element(nums.begin(), nums.end());
        }
        if (sum[0]>=0) {m=sum[0]; l++;}
        else if (sum.size()>1) {m=sum[1]; l=l+2;}
        ans=max(ans, m);
        while (l<sum.size())
        {
            if (l+1==sum.size()) break;
            m=max(m+sum[l]+sum[l+1], sum[l+1]);
            ans=max(ans, m);
            l=l+2;
        }
        return ans;
    }
};
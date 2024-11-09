class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int kk) {
        vector<double> ans(nums.size(), 0), next;
        double sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            ans[i]=sum/(i+1);
        }
        for (int k=2; k<=kk; k++)
        {
            next=ans;
            for (int i=k-1; i<nums.size(); i++)
            {
                sum=0;
                for (int j=i; j<nums.size(); j++)
                {
                    sum+=nums[j];
                    next[j]=max(next[j], ans[i-1]+sum/(j-i+1));
                }
            }
            ans=next;
        }
        return ans[ans.size()-1];
    }
};
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums(nums.size()+1, 0), ans;
        long long sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            sums[i+1]=sum;
        }
        for (int i=1; i!=sums.size(); i++)
        {
            for (int j=i; j!=sums.size(); j++)
            {
                ans.push_back(sums[j]-sums[i-1]);
            }
        }
        sort(ans.begin(), ans.end());
        sum=0;
        for (int i=left-1; i!=right; i++)
        {
            sum+=ans[i];
        }
        return sum%1000000007;
    }
};
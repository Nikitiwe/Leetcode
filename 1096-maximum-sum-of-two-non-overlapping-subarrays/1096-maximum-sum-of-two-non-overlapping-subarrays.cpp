class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int a, int b) {
        vector<int> arr(nums.size()+1, 0);
        int sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            arr[i+1]=sum;
        }
        int ans=0, m=0;
        for (int i=a+b; i<=nums.size(); i++)
        {
            m=max(m, arr[i-b]-arr[i-b-a]);
            ans=max(ans, m+arr[i]-arr[i-b]);
        }
        m=0;
        for (int i=a+b; i<=nums.size(); i++)
        {
            m=max(m, arr[i-a]-arr[i-b-a]);
            ans=max(ans, m+arr[i]-arr[i-a]);
        }
        return ans;
    }
};
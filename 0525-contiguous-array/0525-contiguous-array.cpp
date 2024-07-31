class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int temp=0, n=nums.size(), ans=0;
        vector<int> arr(n*2+1, -2);
        arr[n]=-1;
        for (int i=0; i!=n; i++)
        {
            if (nums[i]==1) temp++;
            else temp--;
            if (arr[n+temp]==-2) arr[n+temp]=i;
            else ans=max(ans, i-arr[n+temp]);
        }
        return ans;
    }
};
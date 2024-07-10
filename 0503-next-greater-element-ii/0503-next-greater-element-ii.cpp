class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int n=nums.size(), f;
        if (n==1) return {-1};
        for (int i=0; i!=n; i++)
        {
            for (int j=(i+1)%n; j!=i; j=(j+1)%n)
            {
                if (i>0&&nums[i-1]<nums[i]&&nums[i]<ans[i-1]) ans[i]=ans[i-1];
                else {
                f=0;
                if (nums[j]>nums[i]) {ans[i]=nums[j]; f=1; break;}
                if (f==0) ans[i]=-1;
                }
            }
        }
        return ans;

    }
};
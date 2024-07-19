class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ans(16, 0);
        int c=0;
        for (int i=0; i!=nums.size(); i++)
        {
            nums[i]+=32768;
            c=0;
            while (nums[i]>0)
            {
                ans[c]+=nums[i]%2;
                nums[i]/=2;
                c++;
            }
        }
        c=0;
        for (int i=15; i>=0; i--)
        {
            ans[i]=ans[i]%2;
            c=c*2+ans[i];
        }
        return c-32768;
    }
};
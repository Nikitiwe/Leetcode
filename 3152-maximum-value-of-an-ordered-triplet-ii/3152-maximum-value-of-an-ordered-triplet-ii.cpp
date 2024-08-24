class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> mil(nums.size(), 0), mtr(nums.size(), 0);
        int mi=nums[0];
        long long ans=0;
        mil[0]=mi;
        for (int i=0; i!=nums.size(); i++)
        {
            mi=max(nums[i], mi);
            mil[i]=mi;
        }
        int ma=nums[nums.size()-1];
        for (int i=nums.size()-1; i>1; i--)
        {
            ma=max(nums[i], ma);
            mtr[i]=ma;
        }
        for (int i=1; i!=nums.size()-1; i++)
        {
            if (nums[i]<mil[i-1]) ans=max(ans, (long long)(mil[i-1]-nums[i])*mtr[i+1]);
        }
        return ans;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            sums[i+1]=(sums[i]+nums[i])%k;
            sums[i+1]=(sums[i+1]+k)%k;
        }
        int ans=0, temp;
        for (int i=0; i!=k; i++)
        {
            temp=0;
            for (int j=0; j!=sums.size(); j++)
            {
                if (sums[j]==i) temp++;
            }
            ans+=temp*(temp-1)/2;
        }
        return ans;
    }
};
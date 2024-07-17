class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0), count(k, 0);
        count[0]++;
        for (int i=0; i!=nums.size(); i++)
        {
            sums[i+1]=(sums[i]+nums[i])%k;
            sums[i+1]=(sums[i+1]+k)%k;
            count[sums[i+1]]++;
        }
        int ans=0;
        for (int i=0; i!=k; i++)
        {
            ans+=count[i]*(count[i]-1)/2;
        }
        return ans;
    }
};
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        while (k>0)
        {
            int i=0;
            while (k>0)
            {
                nums[i]++;
                k--;
                if (i<nums.size()-1&&nums[i+1]<nums[i]) i++;
                else break;
            }
        }
        long long ans=1;
        for (int i=0; i!=nums.size(); i++)
        {
            ans*=nums[i];
            ans%=1000000007;
        }
        return ans;
    }
};
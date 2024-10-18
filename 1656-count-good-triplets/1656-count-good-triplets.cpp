class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if (abs(nums[i]-nums[j])<=a) for (int k=j+1; k<nums.size(); k++)
                {
                    if (abs(nums[j]-nums[k])<=b&&abs(nums[i]-nums[k])<=c) ans++;
                }
            }
        }
        return ans;
    }
};
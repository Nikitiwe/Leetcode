class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0, ans=100001;
        while (l+k<=nums.size())
        {
            ans=min(ans, nums[l+k-1]-nums[l]);
            l++;
        }
        return ans;
    }
};
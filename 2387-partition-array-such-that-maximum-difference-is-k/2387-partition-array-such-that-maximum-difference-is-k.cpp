class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=0, l=0, temp;
        while (l<nums.size())
        {
            temp=l;
            while (l<nums.size()&&nums[l]<=nums[temp]+k)
            { l++; }
            ans++;
        }
        return ans;
    }
};
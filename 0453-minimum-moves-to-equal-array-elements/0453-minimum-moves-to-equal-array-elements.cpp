class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans=0-nums[0]*nums.size();
        for (int i=0; i!=nums.size(); i++)
        {
            ans+=nums[i];
        }
        return ans;
    }
};
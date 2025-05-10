class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long mao = nums[0], mae = nums[0];
        if (nums[0] % 2 == 0) mao -= x;
        else mae -= x;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                mae = max(mae, max(mae + nums[i], mao + nums[i] - x));
            }
            else
            {
                mao = max(mao, max(mao + nums[i], mae + nums[i] - x));
            }
        }
        return max(mae, mao);
    }
};
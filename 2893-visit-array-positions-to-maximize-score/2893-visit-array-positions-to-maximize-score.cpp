class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        /*vector<long long> o(nums.size(), 0), e = o;
        e[0] = nums[0];
        o[0] = nums[0];*/
        long long mao = nums[0], mae = nums[0];
        if (nums[0] % 2 == 0) mao -= x;
        else mae -= x;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                long long a = 0;
                a = max(mae + nums[i], mao + nums[i] - x);
                mae = max(mae, a);
            }
            else
            {
                long long b = 0;
                b = max(mao + nums[i], mae + nums[i] - x);
                mao = max(mao, b);
            }
        }
        return max(mae, mao);
    }
};
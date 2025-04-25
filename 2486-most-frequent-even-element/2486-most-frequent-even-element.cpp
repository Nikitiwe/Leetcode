class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = -1, maxf = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                m[nums[i]]++;
                if (m[nums[i]] > maxf)
                {
                    maxf = m[nums[i]];
                    ans = nums[i];
                }
                else if (m[nums[i]] == maxf)
                {
                    ans = min(nums[i], ans);
                }
            }
        }
        return ans;
    }
};
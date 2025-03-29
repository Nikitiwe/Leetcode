class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int k) {
        vector<int> arr(nums.size(), 10000000);
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = -1;
        for (int i=0; i!=nums.size(); i++)
        {
            sum += nums[i];
            if (m.count(sum-k) != 0)
            {
                arr[m[sum-k] + 1] = i - m[sum-k];
            }
            m[sum] = i;
        }
        int ans = 10000000;
        vector<int> sarr = arr;
        for (int i = sarr.size()-2; i>=0; i--) sarr[i] = min(sarr[i], sarr[i+1]);
        for (int i=0; i!=arr.size(); i++)
        {
            int t = arr[i];
            if (t+i < arr.size())
            {
                t += sarr[t+i];
                ans = min(ans, t);
            }
        }
        if (ans < 10000000) return ans;
        else return -1;
    }
};
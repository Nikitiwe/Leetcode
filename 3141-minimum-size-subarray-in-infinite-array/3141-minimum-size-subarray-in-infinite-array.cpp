class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int k) {
        vector<long> arr(nums.size()*2 + 1, 0);
        for (int i=0; i+1 < arr.size(); i++)
        {
            arr[i+1] += nums[i%nums.size()];
            arr[i+1] += arr[i];
        }
        int add = 0;
        if (k >= arr[nums.size()])
        {
            add += k/arr[nums.size()];
            k %= arr[nums.size()];
        }
        unordered_map<long, int> s;
        int ans = -1;
        s[0] = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            if (s.count(arr[i] - k) > 0) if (ans == -1) ans = i - s[arr[i] - k];
            else ans = min(ans, i - s[arr[i] - k]);
            s[arr[i]] = i;
        }
        if (ans == -1) return ans;
        else return ans + add * nums.size();
    }
};
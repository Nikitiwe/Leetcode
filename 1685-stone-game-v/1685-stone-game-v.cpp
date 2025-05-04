class Solution {
public:
    unordered_map<int, int> m;
    int f(vector<int>& nums, vector<int>& arr, int l, int r)
    {
        if (l >= r) return 0;
        if (m.count(1000*l + r) == 0)
        {
            int ans = 0;
            int suml = 0, sumr = arr[r+1] - arr[l];
            for (int i=l; i<r; i++)
            {
                suml += nums[i];
                sumr -= nums[i];
                if (suml < sumr) ans = max(ans, suml + f(nums, arr, l, i));
                else if (suml == sumr) ans = max({ans, suml + f(nums, arr, l, i), sumr + f(nums, arr, i+1, r)});
                else ans = max(ans, sumr + f(nums, arr, i+1, r));
            }
            m[1000*l + r] = ans;
        }
        return m[1000*l + r];
    }

    int stoneGameV(vector<int>& nums) {
        vector<int> arr(nums.size() + 1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i+1] += nums[i];
            arr[i+1] += arr[i];
        }
        return f(nums, arr, 0, nums.size()-1);
    }
};
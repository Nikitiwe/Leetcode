class Solution {
public:
    unordered_map<int, int> m;

    int f(vector<int>& nums, int l, int r, int k)
    {
        if (l>r) return 0;
        if (m.count(100000*l + r) == 0)
        {
            int ans = 2000000000;
            int sum = 0;
            unordered_map<int, int> c;
            for (int i=l; i<=r; i++)
            {
                c[nums[i]]++;
                if (c[nums[i]] == 2) sum += 2;
                else if (c[nums[i]] > 2) sum ++;
                ans = min(ans, sum + k + f(nums, i+1, r, k));
            }
            m[100000*l + r] = ans;
        }
        return m[100000*l + r];
    }

    int minCost(vector<int>& nums, int k) {
        return f(nums, 0, nums.size()-1, k);
    }
};
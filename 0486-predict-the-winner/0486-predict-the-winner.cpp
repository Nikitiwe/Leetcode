class Solution {
public:
    unordered_map<int, int> m;
    int f(vector<int>& nums, int l, int r)
    {
        if (l == r) return nums[l];
        if (m.count(100*l+r) == 0) m[100*l+r] = max(nums[l] - f(nums, l+1, r), nums[r] - f(nums, l, r-1));
        return m[100*l+r];
    }

    bool predictTheWinner(vector<int>& nums) {
        int a = f(nums, 0, nums.size()-1);
        if (a >= 0) return 1;
        else return 0;
    }
};
class Solution {
public:
    int f(int n)
    {
        int res = 0;
        while (n > 0)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int smallestIndex(vector<int>& nums) {
        for (int i=0; i!=nums.size(); i++)
        {
            if (i == f(nums[i])) return i;
        }
        return -1;
    }
};
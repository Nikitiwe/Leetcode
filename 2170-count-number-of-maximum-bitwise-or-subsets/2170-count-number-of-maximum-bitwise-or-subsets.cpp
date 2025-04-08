class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int count = 0, ans = -1, k = 1;
        for (int i=0; i!=nums.size(); i++) k *= 2;
        while (k > 0)
        {
            int t = k;
            int a = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                if (t%2 == 1)
                {
                    a |= nums[i];
                }
                t /= 2;
            }
            if (a > ans)
            {
                ans = a;
                count = 1;
            }
            else if (a == ans) count++;
            k--;
        }
        return count;
    }
};
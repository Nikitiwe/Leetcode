class Solution {
public:
    int minSwaps(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int r1 = 0, r0 = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] % 2 == 0) r0++;
            else r1++;
        }
        if (abs(r1 - r0) > 1) return -1;
        int ans = 2e9;
        if (r1 - r0 == 1)
        {
            int t = 0;
            int id = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i] % 2 == 1)
                {
                    t += abs(id - i);
                    id += 2;
                }
            }
            ans = min(ans, t);
        }
        else if (r1 - r0 == 0)
        {
            int t = 0;
            int id = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i] % 2 == 1)
                {
                    t += abs(id - i);
                    id += 2;
                }
            }
            ans = min(ans, t);
            t = 0;
            id = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i] % 2 == 0)
                {
                    t += abs(id - i);
                    id += 2;
                }
            }
            ans = min(ans, t);
        }
        else
        {
            int t = 0;
            int id = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i] % 2 == 0)
                {
                    t += abs(id - i);
                    id += 2;
                }
            }
            ans = min(ans, t);
        }
        return ans;
    }
};
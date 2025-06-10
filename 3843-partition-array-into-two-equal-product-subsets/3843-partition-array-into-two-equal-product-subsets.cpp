class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int a = 1;
        for (int i=0; i<nums.size(); i++) a *= 2;
        for (int kk = 1; kk<a; kk += 2)
        {
            long long p = 1;
            int k = kk;
            int j = 0;
            while (k > 0)
            {
                if (k % 2 == 1) p *= nums[j];
                if (p > target) break;
                j++;
                k /= 2;
            }
            if (p == target)
            {
                long long p = 1;
                int k = kk;
                for (int i=0; i!=nums.size(); i++)
                {
                    if (k % 2 == 0) p *= nums[i];
                    if (p > target) break;
                    k /= 2;
                }
                if (p == target) return 1;
                else return 0;
            }
        }
        return 0;
    }
};
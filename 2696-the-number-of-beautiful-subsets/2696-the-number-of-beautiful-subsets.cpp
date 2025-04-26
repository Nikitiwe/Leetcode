class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int kk) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int k = 1, a = nums.size();
        while (a > 0)
        {
            k *= 2;
            a--;
        }
        for (int b = 1; b<k; b++)
        {
            bool isit = 1;
            int t = b;
            unordered_set<int> s;
            for (int i = 0; i!=nums.size(); i++)
            {
                if (t%2 == 1)
                {
                    if (s.count(nums[i] - kk) == 1)
                    {
                        isit = 0;
                        break;
                    }
                    else s.insert(nums[i]);
                }
                t /= 2;
            }
            if (isit == 1) ans++;
        }
        return ans;
    }
};
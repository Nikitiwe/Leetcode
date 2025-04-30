class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int t) {
        long long ans = 0;
        vector<int> arr(nums.size(), 0);
        vector<int> c(33, 0);
        vector<bool> isit(nums.size(), 1);
        for (int i=0; i!=nums.size(); i++)
        {
            int tt = nums[i];
            while (tt > 0)
            {
                arr[i] += tt%2;
                tt/=2;
            }
        }
        for (int k = 0; k < 33; k++)
        {
            unordered_set<int> s;
            for (int i=0; i!=nums.size(); i++)
            {
                if (arr[i] == k) s.insert(nums[i]);
            }
            c[k] = s.size();
        }
        for (int i=0; i!=c.size(); i++)
        {
            for (int j=0; j!=c.size(); j++)
            {
                if (i+j >= t) ans += c[i] * c[j];
            }
        }
        /*for (int i=0; i!=nums.size(); i++)
        {
            if (arr[i]*2 >= t) ans--;
        }*/
        return ans;
    }
};
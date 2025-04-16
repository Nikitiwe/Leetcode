class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        nums.push_back(-1);
        unordered_map<int, int> l, r;
        int a = 0, b = 0;
        while (a < nums.size() && l.size() < k)
        {
            l[nums[a]]++;
            a++;
        }
        while (b < nums.size() && r.size() < k + 1)
        {
            r[nums[b]]++;
            b++;
        }
        if (l.size() == k && r.size() == k + 1) ans += b-a;
        for (int i=0; i!=nums.size(); i++)
        {
            l[nums[i]]--;
            if (l[nums[i]] == 0) l.erase(nums[i]);
            r[nums[i]]--;
            if (r[nums[i]] == 0) r.erase(nums[i]);
            while (a < nums.size() && l.size() < k)
            {
                l[nums[a]]++;
                a++;
            }
            while (b < nums.size() && r.size() < k + 1)
            {
                r[nums[b]]++;
                b++;
            }
            if (l.size() == k && r.size() == k + 1) ans += b-a;
        }
        return ans;
    }
};
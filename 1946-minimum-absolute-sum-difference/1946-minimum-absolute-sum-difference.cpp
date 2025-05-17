class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums, vector<int>& nums2) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int add = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            int d = abs(nums[i] - nums2[i]);
            if (add >= d) continue;
            int l = 0, r = arr.size()-1, m, t = d;
            while (l <= r)
            {
                m = (l+r)/2;
                if (arr[m] > nums2[i])
                {
                    t = min(t, arr[m] - nums2[i]);
                    r = m-1;
                }
                else
                {
                    l = m+1;
                    t = min(t, nums2[i] - arr[m]);
                }
            }
            add = max(add, d - t);
        }
        long ans = -add;
        for (int i=0; i!=nums.size(); i++) ans += abs(nums[i] - nums2[i]);
        return ans % (1000000007);
    }
};
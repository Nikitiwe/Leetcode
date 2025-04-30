class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> arr(33, 1000000);
        vector<int> ans(nums.size(), 1);
        for (int i=nums.size() - 1; i>=0; i--)
        {
            int t = nums[i];
            vector<int> tarr(33, 0);
            int a = 0;
            while (t > 0)
            {
                tarr[a] = t%2;
                t /= 2;
                a++;
            }
            for (int j=0; j<33; j++)
            {
                if (tarr[j] == 1) arr[j] = min(arr[j], i);
            }
            for (int j=0; j<33; j++)
            {
                if (arr[j] < 1000000) ans[i] = max(ans[i], arr[j] - i + 1);
            }
        }
        return ans;
    }
};
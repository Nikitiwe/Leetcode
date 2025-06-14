class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<int> arr(3, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            int t = nums[i];
            int c = 1;
            while (t > 0)
            {
                c *= 2;
                t /= 2;
            }
            arr[i] = c;
        }
        int ans = 0;
        ans = max(ans, nums[0]*(arr[1]*arr[2]) + nums[1]*(arr[2]) + nums[2]);
        ans = max(ans, nums[0]*(arr[1]*arr[2]) + nums[2]*(arr[1]) + nums[1]);
        ans = max(ans, nums[1]*(arr[0]*arr[2]) + nums[0]*(arr[2]) + nums[2]);
        ans = max(ans, nums[1]*(arr[0]*arr[2]) + nums[2]*(arr[0]) + nums[0]);
        ans = max(ans, nums[2]*(arr[1]*arr[0]) + nums[1]*(arr[0]) + nums[0]);
        ans = max(ans, nums[2]*(arr[1]*arr[0]) + nums[0]*(arr[1]) + nums[1]);
        return ans;
    }
};
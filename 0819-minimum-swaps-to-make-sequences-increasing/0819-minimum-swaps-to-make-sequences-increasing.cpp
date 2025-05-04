class Solution {
public:
    int minSwap(vector<int>& nums, vector<int>& arr) {
        vector<int> s(nums.size(), 10000000), k = s;
        s[0] = 1;
        k[0] = 0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1] < nums[i] && arr[i-1] < arr[i] && nums[i-1] < arr[i] && arr[i-1] < nums[i])
            {
                k[i] = min(k[i-1], s[i-1]);
                s[i] = 1 + min(k[i-1], s[i-1]);
            }
            else if (nums[i-1] < nums[i] && arr[i-1] < arr[i])
            {
                k[i] = k[i-1];
                s[i] = 1 + s[i-1];
            }
            else //if (nums[i-1] >= nums[i] || arr[i-1] >= arr[i])
            {
                k[i] = s[i-1];
                s[i] = 1 + k[i-1];
            }
        }
        return min(s.back(), k.back());
    }
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ma = 0;
        for (int i=0; i!=nums.size(); i++) ma = max(ma, nums[i]);
        vector<int> arr(ma+1, 0), y = arr, n = arr;
        for (int i=0; i!=nums.size(); i++) arr[nums[i]]++;
        y[1] = arr[1];
        for (int i=2; i!=arr.size(); i++)
        {
            y[i] = arr[i]*i + max(y[i-2], n[i-1]);
            n[i] = max(y[i-1], n[i-1]);
        }
        return max(y[ma], n[ma]);
    }
};
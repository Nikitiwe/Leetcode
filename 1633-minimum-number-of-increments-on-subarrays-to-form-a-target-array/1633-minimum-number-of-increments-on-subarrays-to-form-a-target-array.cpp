class Solution {
public:
    int minNumberOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> arr(1, 0);
        for (int i=0; i<nums.size(); i++) if (nums[i] != arr.back()) arr.push_back(nums[i]);
        arr.push_back(0);
        for (int i=1; i<arr.size()-1; i++)
        {
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) ans += arr[i];
            else if (arr[i-1] > arr[i] && arr[i] < arr[i+1]) ans -= arr[i];
        }
        return ans;
    }
};
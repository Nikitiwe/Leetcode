class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr(1, nums[0]);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]!=arr.back()) arr.push_back(nums[i]);
        }
        int ans=0;
        for (int i=1; i<arr.size()-1; i++)
        {
            if ((arr[i-1]<arr[i]&&arr[i]>arr[i+1])||(arr[i-1]>arr[i]&&arr[i]<arr[i+1])) ans++;
        }
        return ans;
    }
};
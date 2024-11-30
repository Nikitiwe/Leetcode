class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> arr;
        int t=1, ans=0;
        nums.push_back(-2000000000);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>nums[i-1]) t++;
            else
            {
                arr.push_back(t);
                t=1;
            }
        }
        for (int i=0; i<arr.size(); i++) ans=max(ans, arr[i]/2);
        for (int i=0; i<arr.size()-1; i++) ans=max(ans, min(arr[i], arr[i+1]));
        return ans;
    }
};
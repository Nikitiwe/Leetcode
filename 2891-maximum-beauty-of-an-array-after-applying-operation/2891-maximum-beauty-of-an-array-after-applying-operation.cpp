class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=*min_element(nums.begin(), nums.end());
        vector<int> arr(*max_element(nums.begin(), nums.end())-n+1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]-k<n) arr[0]++;
            else arr[nums[i]-k-n]++;
            if (nums[i]+k+1>arr.size()-1+n) ;
            else arr[nums[i]+k+1-n]--;
        }
        for (int i=0; i<arr.size()-1; i++) arr[i+1]+=arr[i];
        return *max_element(arr.begin(), arr.end());
    }
};
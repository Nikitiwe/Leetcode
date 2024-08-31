class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> arr(*max_element(nums.begin(), nums.end())+1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]-k<0) arr[0]++;
            else arr[nums[i]-k]++;
            if (nums[i]+k+1>arr.size()-1) ;
            else arr[nums[i]+k+1]--;
        }
        for (int i=0; i<arr.size()-1; i++) arr[i+1]+=arr[i];
        return *max_element(arr.begin(), arr.end());
    }
};
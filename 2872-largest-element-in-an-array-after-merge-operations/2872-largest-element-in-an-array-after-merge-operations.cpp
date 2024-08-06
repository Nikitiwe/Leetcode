class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> arr;
        for (int i=0; i!=nums.size(); i++)
        {
            arr.push_back(nums[i]);
        }
        int r=nums.size()-2;
        long long ans=arr[0];
        while (r>=0)
        {
            if (arr[r]<=arr[r+1]) arr[r]+=arr[r+1];
            ans=max(ans, arr[r]);
            r--;
        }
        return ans;
    }
};
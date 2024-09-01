class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        vector<int> arr(nums.size()+1, 0);
        for (int i=0; i!=req.size(); i++)
        {
            arr[req[i][0]]++;
            arr[req[i][1]+1]--;
        }
        for (int i=1; i<arr.size(); i++) arr[i]+=arr[i-1];
        sort(arr.rbegin(), arr.rend());
        sort(nums.rbegin(), nums.rend());
        long ans=0;
        for (int i=0; i!=nums.size(); i++) ans+=(long)arr[i]*nums[i];
        return ans%1000000007;
    }
};
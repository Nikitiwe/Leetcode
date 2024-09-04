class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans, arr(nums.size()-1, 0);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]==nums[i-1]+1) arr[i-1]++;
        }
        int temp=0;
        for (int i=0; i<k-1; i++) temp+=arr[i];
        if (temp==k-1) ans.push_back(nums[k-1]);
        else ans.push_back(-1);
        for (int i=k-1; i<arr.size(); i++)
        {
            temp+=arr[i];
            temp-=arr[i-k+1];
            if (temp==k-1) ans.push_back(nums[i+1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
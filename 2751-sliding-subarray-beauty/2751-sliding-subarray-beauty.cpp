class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> arr(101, 0), ans;
        for (int i=0; i<k-1; i++)
        {
            arr[nums[i]+50]++;
        }
        for (int i=k-1; i<=k-1; i++)
        {
            arr[nums[i]+50]++;
            int l=0, s=0;
            while (l<=50&&s<x)
            {
                s+=arr[l];
                l++;
            }
            if (l<=51) ans.push_back(l-51);
            else ans.push_back(0);
        }
        for (int i=k; i<nums.size(); i++)
        {
            arr[nums[i]+50]++;
            arr[nums[i-k]+50]--;
            int l=0, s=0;
            while (l<=50&&s<x)
            {
                s+=arr[l];
                l++;
            }
            if (l<=51) ans.push_back(l-51);
            else ans.push_back(0);
        }
        return ans;
    }
};
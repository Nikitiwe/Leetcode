class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        vector<vector<int>> arr(nums.size(), vector<int> (2, 0));
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i][0]=nums[i];
            arr[i][1]=i;
        }
        sort(arr.begin(), arr.end());
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[arr[i][1]]!=-1)
            {
                ans+=arr[i][0];
                if (arr[i][1]>0) nums[arr[i][1]-1]=-1;
                if (arr[i][1]<nums.size()-1) nums[arr[i][1]+1]=-1;
            }
        }
        return ans;
    }
};
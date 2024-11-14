class Solution {
public:
    bool isCovered(vector<vector<int>>& nums, int l, int r) {
        vector<int> arr(52, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[nums[i][0]]++;
            arr[nums[i][1]+1]--;
        }
        for (int i=1; i<=r; i++)
        {
            arr[i]+=arr[i-1];
        }
        for (int i=l; i<=r; i++)
        {
            if (arr[i]==0) return 0;
        }
        return 1;
    }
};
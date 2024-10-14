class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> arr(102, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[nums[i][0]]++;
            arr[nums[i][1]+1]--;
        }
        int ans=0;
        for (int i=1; i!=arr.size(); i++)
        {
            arr[i]+=arr[i-1];
            if (arr[i]>0) ans++;
        }
        return ans;
    }
};
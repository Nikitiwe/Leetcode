class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> arr(nums.size()+1, 0);
        bool isit=0;
        for (int i=0; i!=q.size(); i++)
        {
            arr[q[i][0]]+=1;
            arr[q[i][1]+1]-=1;
        }
        if (arr[0]<nums[0]) return 0;
        if (nums[0]>0) isit=1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>0) isit=1;
            arr[i]+=arr[i-1];
            if (arr[i]<nums[i]) return 0;
        }
        if (isit==0) return 0;
        return 1;
    }
};
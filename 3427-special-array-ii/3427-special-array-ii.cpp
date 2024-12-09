class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> arr(nums.size(), 0);
        arr[0]=1;
        int t=1;
        for (int i=1; i!=nums.size(); i++)
        {
            if ((nums[i]+nums[i-1])%2==1) t++;
            else t=1;
            arr[i]=t;
        }
        vector<bool> ans(q.size(), 0);
        for (int i=0; i!=q.size(); i++)
        {
            if (arr[q[i][1]]>q[i][1]-q[i][0]) ans[i]=1;
        }
        return ans;
    }
};
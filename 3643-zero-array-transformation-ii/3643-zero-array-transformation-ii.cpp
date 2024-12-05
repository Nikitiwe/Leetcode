class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> arr(nums.size()+1, 0);
        bool isit=0;
        for (int i=0; i!=q.size(); i++)
        {
            arr[q[i][0]]+=q[i][2];
            arr[q[i][1]+1]-=q[i][2];
        }
        if (arr[0]<nums[0]) return -1;
        if (nums[0]>0) isit=1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>0) isit=1;
            arr[i]+=arr[i-1];
            if (arr[i]<nums[i]) return -1;
        }
        if (isit==0) return 0;
        int l=0, r=q.size(), m, ans=q.size();
        while (l<=r)
        {
            isit=1;
            m=(l+r)/2;
            vector<int> ar(nums.size()+1, 0);
            for (int i=0; i<m; i++)
            {
                ar[q[i][0]]+=q[i][2];
                ar[q[i][1]+1]-=q[i][2];
            }
            if (ar[0]<nums[0]) isit=0;
            else for (int i=1; i<nums.size(); i++)
            {
                ar[i]+=ar[i-1];
                if (ar[i]<nums[i])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1)
            {
                ans=min(ans, m);
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};
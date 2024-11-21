class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
        vector<vector<int>> arr(nums.size()+1, vector<int> (101, 0));
        arr[1][nums[0]]++;
        for (int i=1; i<nums.size(); i++)
        {
            arr[i+1]=arr[i];
            arr[i+1][nums[i]]++;
        }
        vector<int> ans(q.size(), -1);
        for (int i=0; i!=q.size(); i++)
        {
            int k=0, a=200;
            for (int j=1; j!=101; j++)
            {
                if (arr[q[i][1]+1][j]-arr[q[i][0]][j]>0)
                {
                    if (k==0) k=j;
                    else
                    {
                        a=min(a, j-k);
                        k=j;
                    }
                }
            }
            if (a!=200) ans[i]=a;
        }
        return ans;
    }
};
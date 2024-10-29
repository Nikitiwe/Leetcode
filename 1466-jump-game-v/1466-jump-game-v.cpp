class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> ans(n, 1);
        vector<vector<int>> nums(n, vector<int> (2, 0));
        for (int i=0; i!=n; i++)
        {
            nums[i][0]=arr[i];
            nums[i][1]=i;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i!=n; i++)
        {
            int id=nums[i][1];
            for (int j=id+1; j<=min(n-1, id+d); j++)
            {
                if (arr[id]>arr[j]) ans[id]=max(ans[id], ans[j]+1);
                else break;
            }
            for (int j=id-1; j>=max(0, id-d); j--)
            {
                if (arr[id]>arr[j]) ans[id]=max(ans[id], ans[j]+1);
                else break;
            }
        }
        int t=0;
        for (int i=0; i!=n; i++) t=max(t, ans[i]);
        return t;
    }
};
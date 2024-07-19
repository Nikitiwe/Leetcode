class Solution {
public:
    int numSquares(int n) {
        vector<int> ans(n+1, 999);
        ans[0]=0;
        int temp;
        while (ans[n]==999)
        {
            for (int j=1; j<=n; j++)
            {
                for (int i=1; i<=100; i++)
                {
                    temp=j-i*i;
                    if(temp>=0&&ans[temp]!=999) ans[j]=min(ans[temp]+1, ans[j]);
                }
            }
        }
        return ans[n];
    }
};
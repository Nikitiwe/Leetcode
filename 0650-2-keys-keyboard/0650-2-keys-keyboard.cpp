class Solution {
public:
    int minSteps(int n) {
        if (n==1) return 0;
        vector<vector<int>> arr;
        vector<int> row(n+1, 0);
        for (int i=0; i<=n/2+2; i++)
        {
            arr.push_back(row);
        }
        arr[1][1]=1;
        for (int i=1; i!=arr.size(); i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (arr[i][j]!=0)
                {
                    if (i+j<=n) arr[i][j+i]=arr[i][j]+1;
                    if (j<arr.size()) arr[j][j]=arr[i][j]+1;
                }
            }
        }
        int m=2001;
        for (int i=1; i!=arr.size(); i++)
        {
            if (arr[i][n]!=0) m=min(m, arr[i][n]);
        }
        return m;
    }
};
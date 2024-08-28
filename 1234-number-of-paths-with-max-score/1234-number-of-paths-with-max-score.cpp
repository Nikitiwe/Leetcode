class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>> arr(n, vector<int> (n, 0));
        vector<vector<int>> sum(n, vector<int> (n, 0));
        arr[n-1][n-1]=1;
        board[0][0]='0';

        for (int i=n-2; i>=0; i--)
        {
            if (board[i][n-1]!='X')
            {
                sum[i][n-1]+=sum[i+1][n-1]+board[i][n-1]-'0';
                arr[i][n-1]+=arr[i+1][n-1];
            }
            else break;
        }

        for (int j=n-2; j>=0; j--)
        {
            if (board[n-1][j]!='X')
            {
                sum[n-1][j]+=sum[n-1][j+1]+board[n-1][j]-'0';
                arr[n-1][j]+=arr[n-1][j+1];
            }
            else break;
        }

        for (int i=n-2; i>=0; i--)
        {
            for (int j=n-2; j>=0; j--)
            {
                if (board[i][j]!='X')
                {
                    int t=max({sum[i+1][j], sum[i+1][j+1], sum[i][j+1]});
                    sum[i][j]=t+board[i][j]-'0';
                    if (sum[i+1][j]==t) arr[i][j]+=arr[i+1][j];
                    if (sum[i+1][j+1]==t) arr[i][j]+=arr[i+1][j+1];
                    if (sum[i][j+1]==t) arr[i][j]+=arr[i][j+1];
                    arr[i][j]%=1000000007;
                }
            }
        }
        if (arr[0][0]==0) return {0,0};
        return {sum[0][0], arr[0][0]};
    }
};
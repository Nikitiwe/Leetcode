class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int sum;
        for (int i=0; i!=board.size(); i++)
        {
            for (int j=0; j!=board[0].size(); j++)
            {
                sum=0;
                if (i!=0&&j!=0) sum=sum+board[i-1][j-1]%2;
                if (i!=board.size()-1&&j!=board[0].size()-1) sum=sum+board[i+1][j+1];
                if (i!=0&&j!=board[0].size()-1) sum=sum+board[i-1][j+1]%2;
                if (i!=board.size()-1&&j!=0) sum=sum+board[i+1][j-1]%2;
                if (i!=0) sum=sum+board[i-1][j]%2;
                if (i!=board.size()-1) sum=sum+board[i+1][j];
                if (j!=0) sum=sum+board[i][j-1]%2;
                if (j!=board[0].size()-1) sum=sum+board[i][j+1];
                if (sum<=2&&board[i][j]==0) board[i][j]=2;
                if (sum==2&&board[i][j]==1) board[i][j]=5;
                if (sum<2&&board[i][j]==1) board[i][j]=3;
                if (sum==3&&board[i][j]==0) board[i][j]=4;
                if (sum==3&&board[i][j]==1) board[i][j]=5;
                if (sum>3&&board[i][j]==0) board[i][j]=2;
                if (sum>3&&board[i][j]==1) board[i][j]=3;
            }
        }
        for (int i=0; i!=board.size(); i++)
        {
            for (int j=0; j!=board[0].size(); j++)
            {
                if (board[i][j]<=3) board[i][j]=0;
                else board[i][j]=1;
            }
        }
    }
};
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> pos(n+1, 0);
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (i>=j*j) { if (pos[i-j*j]==0) {pos[i]=1; break;} }
                else {pos[i]=0; break;}
            }
        }
        return pos[n];
    }
};
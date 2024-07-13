class Solution {
public:
    int knightDialer(int n) {
        vector<vector<long long>> ans{{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, prew{{1,1,1},{1,1,1},{1,1,1},{0,1,0}};
        for (int i=1; i!=n; i++)
        {
            ans[0][0]=(prew[1][2]+prew[2][1])%1000000007;
            ans[0][1]=(prew[2][0]+prew[2][2])%1000000007;
            ans[0][2]=(prew[1][0]+prew[2][1])%1000000007;
            ans[1][0]=(prew[0][2]+prew[2][2]+prew[3][1])%1000000007;
            ans[1][1]=0;
            ans[1][2]=(prew[0][0]+prew[2][0]+prew[3][1])%1000000007;
            ans[2][0]=(prew[0][1]+prew[1][2])%1000000007;
            ans[2][1]=(prew[0][0]+prew[0][2])%1000000007;
            ans[2][2]=(prew[0][1]+prew[1][0])%1000000007;
            ans[3][1]=(prew[1][0]+prew[1][2])%1000000007;
            prew=ans;
        }
        return (prew[0][0]+prew[0][1]+prew[0][2]+prew[1][0]+prew[1][1]+prew[1][2]
        +prew[2][0]+prew[2][1]+prew[2][2]+prew[3][1])%1000000007;
    }
};
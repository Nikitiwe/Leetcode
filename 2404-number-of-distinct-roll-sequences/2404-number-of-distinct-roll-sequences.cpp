class Solution {
public:
    int distinctSequences(int n) {
        if (n==1) return 6;
        vector<long long> row={0,0,0,0,0,0};
        vector<vector<long long>> next={row,row,row,row,row,row},
        prew={row,row,row,row,row,row}, zero={row,row,row,row,row,row};
        prew[0][1]=1; prew[0][2]=1; prew[0][3]=1; prew[0][4]=1; prew[0][5]=1;
        prew[1][0]=1; prew[1][2]=1; prew[1][4]=1;
        prew[2][0]=1; prew[2][1]=1; prew[2][3]=1; prew[2][4]=1;
        prew[3][0]=1; prew[3][2]=1; prew[3][4]=1;
        prew[4][0]=1; prew[4][1]=1; prew[4][2]=1; prew[4][3]=1; prew[4][5]=1;
        prew[5][0]=1; prew[5][4]=1;
        for (int i=2; i!=n; i++)
        {
            for (int a=0; a!=6; a++)
            {
                for (int k=0; k!=6; k++)
                {
                    for (int j=0; j!=6; j++)
                    {
                        if (a!=k&&a!=j&&gcd(a+1, k+1)==1) next[k][a]+=prew[j][k];
                    }
                    next[k][a]%=1000000007;
                }
            }
            prew=next;
            next=zero;
        }
        long long ans=0;
        for (int a=0; a!=6; a++)
        {
            for (int k=0; k!=6; k++)
            {
                ans+=prew[a][k];
            }
        }
        ans%=1000000007;
        return ans;
    }
};
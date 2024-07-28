class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (arrLen==1) return 1;
        vector<long long> pr(min(251, arrLen), 0), ne(min(251, arrLen), 0);
        pr[0]=1;
        for (int i=0; i!=steps; i++)
        {
            for (int j=0; j<=i+1&&j<=steps-i-1&&j<pr.size(); j++)
            {
                if (j==0) ne[j]=pr[j]+pr[j+1];
                else if (j==pr.size()-1) ne[j]=pr[j-1]+pr[j];
                else ne[j]=pr[j-1]+pr[j]+pr[j+1];
                ne[j]%=1000000007;
            }
            pr=ne;
        }
        return pr[0];
    }
};
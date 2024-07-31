class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long long>> next, prev, zero;
        for (int i=0; i!=rollMax.size(); i++)
        {
            vector<long long> t(rollMax[i], 0);
            prev.push_back(t);
        }
        next=prev;
        zero=prev;
        for (int i=0; i!=rollMax.size(); i++)
        {
            prev[i][0]=1;
        }
        long long ans=0;
        for (int i=2; i<=n; i++)
        {
            for (int j=0; j!=6; j++)
            {
                for (int k=0; k!=6; k++)
                {
                    if (k==j) for (int a=1; a!=rollMax[k]; a++)
                    {
                        next[j][a]+=prev[j][a-1];
                    }
                    else for (int a=0; a!=rollMax[k]; a++)
                    {
                        next[j][0]+=prev[k][a];
                    }
                }
            }
            for (int k=0; k!=6; k++)
            {
                for (int a=0; a!=rollMax[k]; a++)
                {
                 next[k][a]%=1000000007;
                }
            }
            prev=next;
            next=zero;
        }
        for (int k=0; k!=6; k++)
        {
            for (int a=0; a!=rollMax[k]; a++)
            {
                ans+=prev[k][a];
            }
        }
        return ans%1000000007;
    }
};
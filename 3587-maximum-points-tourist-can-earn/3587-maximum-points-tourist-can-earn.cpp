class Solution {
public:
    int maxScore(int n, int kk, vector<vector<int>>& s, vector<vector<int>>& t) {
        vector<int> prev(n, 0), next=prev, zero=prev;
        for (int k=0; k<kk; k++)
        {
            for (int i=0; i!=n; i++) next[i]=prev[i]+s[k][i];
            for (int i=0; i!=n; i++)
            {
                for (int j=0; j!=n; j++)
                {
                    if (j!=i)
                    {
                        next[i]=max(next[i], prev[j]+t[j][i]);
                    }
                }
            }
            prev=next;
            next=zero;
        }
        return *max_element(prev.begin(), prev.end());
    }
};
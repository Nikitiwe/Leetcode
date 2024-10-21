class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        vector<int> ans(2, 0);
        unordered_set<int> m;
        int sum=0, c=0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (ans[0]==0)
                {
                    c++;
                    m.insert(g[i][j]);
                    if (m.size()<c)
                    {
                        ans[0]=g[i][j];
                    }
                }
                sum+=g[i][j];
            }
        }
        ans[1]=(g.size()*g.size()+1)*g.size()*g.size()/2-sum+ans[0];
        return ans;
    }
};
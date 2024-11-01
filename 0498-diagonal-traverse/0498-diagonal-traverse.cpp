class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& m) {
        vector<int> ans;
        for (int k=0; k!=m.size()+m[0].size(); k++)
        {
            if (k%2==0)
            {
                for (int i=k-m.size()+1; i<=k; i++)
                {
                    if (i<m[0].size()) ans.push_back(m[k-i][i]);
                }
            }
            else
            {
                for (int i=0; i<=k; i++)
                {
                    if (i<m.size()&&k-i<m[0].size()) ans.push_back(m[i][k-i]);
                }
            }
        }
        return ans;
    }
};
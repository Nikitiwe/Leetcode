class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        unordered_set<int> row, col, id;
        for (int i=q.size()-1; i>=0; i--)
        {
            if (q[i][0]==0)
            {
                if (row.count(q[i][1])==0)
                {
                    row.insert(q[i][1]);
                    id.insert(i);
                }
            }
            else
            {
                if (col.count(q[i][1])==0)
                {
                    col.insert(q[i][1]);
                    id.insert(i);
                }
            }
        }
        long long ans=0, r=n, c=n;
        for (int i=q.size()-1; i>=0; i--)
        {
            if (id.count(i)>0)
            {
                if (q[i][0]==0)
                {
                    ans+=c*q[i][2];
                    r--;
                }
                else
                {
                    ans+=r*q[i][2];
                    c--;
                }
            }
        }
        return ans;
    }
};
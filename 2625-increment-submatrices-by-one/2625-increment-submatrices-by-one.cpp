class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> m;
        vector<int> row(n, 0);
        for (int i=0; i!=n; i++) m.push_back(row);
        for (int i=0; i!=queries.size(); i++)
        {
            m[queries[i][0]][queries[i][1]]++;
            if (queries[i][2]+1<n) m[queries[i][2]+1][queries[i][1]]--;
            if (queries[i][3]+1<n) m[queries[i][0]][queries[i][3]+1]--;
            if (queries[i][2]+1<n&&queries[i][3]+1<n) m[queries[i][2]+1][queries[i][3]+1]++;
        }
        for (int i=1; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                m[i][j]+=m[i-1][j];
            }
        }
        for (int i=0; i!=n; i++)
        {
            for (int j=1; j!=n; j++)
            {
                m[i][j]+=m[i][j-1];
            }
        }
        return m;
    }
};
class Solution {
public:
    bool findRotation(vector<vector<int>>& m, vector<vector<int>>& t) {
        if (m==t) return 1;
        int n=m.size();
        bool isit=1;
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (m[i][j]!=t[j][n-1-i])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        if (isit==1) return 1;
        isit=1;
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (m[i][j]!=t[n-1-i][n-1-j])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        if (isit==1) return 1;
        isit=1;
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (m[i][j]!=t[n-1-j][i])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        if (isit==1) return 1;
        else return 0;
    }
};
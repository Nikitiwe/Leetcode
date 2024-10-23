class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& q, vector<int>& k) {
        vector<vector<int>> ans;
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]+i<8&&k[0]+i==q[j][0]&&k[1]+i<8&&k[1]+i==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]==q[j][0]&&k[1]+i<8&&k[1]+i==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]+i<8&&k[0]+i==q[j][0]&&k[1]==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]-i>=0&&k[0]-i==q[j][0]&&k[1]-i>=0&&k[1]-i==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]==q[j][0]&&k[1]-i>=0&&k[1]-i==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]-i>=0&&k[0]-i==q[j][0]&&k[1]==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]+i<8&&k[0]+i==q[j][0]&&k[1]-i>=0&&k[1]-i==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        for (int i=1; i<=7; i++)
        {
            bool isit=1;
            for (int j=0; j!=q.size(); j++)
            {
                if (k[0]-i>=0&&k[0]-i==q[j][0]&&k[1]+i<8&&k[1]+i==q[j][1])
                {
                    ans.push_back(q[j]);
                    isit=0;
                    break;
                }
            }
            if (isit==0) break;
        }
        return ans;
    }
};
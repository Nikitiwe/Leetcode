class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;
        ans.push_back(m[0][0]);
        m[0][0]=-200;
        int x=0, y=0;
        while (ans.size()<m.size()*m[0].size())
        {
            while (y+1<m[0].size()&&m[x][y+1]!=-200)
            {
                y++;
                ans.push_back(m[x][y]);
                m[x][y]=-200;
            }
            while (x+1<m.size()&&m[x+1][y]!=-200)
            {
                x++;
                ans.push_back(m[x][y]);
                m[x][y]=-200;
            }
            while (y-1>=0&&m[x][y-1]!=-200)
            {
                y--;
                ans.push_back(m[x][y]);
                m[x][y]=-200;
            }
            while (x-1>=0&&m[x-1][y]!=-200)
            {
                x--;
                ans.push_back(m[x][y]);
                m[x][y]=-200;
            }
        }
        return ans;
    }
};
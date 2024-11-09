class Solution {
public:
    string tictactoe(vector<vector<int>>& m) {
        vector<vector<int>> g(3, vector<int> (3, 0));
        for (int i=0; i!=m.size(); i++)
        {
            if (i%2==0)
            {
                g[m[i][0]][m[i][1]]=1;
                if (g[0][0]==1&&g[1][1]==1&&g[2][2]==1) return "A";
                if (g[0][2]==1&&g[1][1]==1&&g[2][0]==1) return "A";
                if (g[0][0]==1&&g[0][1]==1&&g[0][2]==1) return "A";
                if (g[1][0]==1&&g[1][1]==1&&g[1][2]==1) return "A";
                if (g[2][0]==1&&g[2][1]==1&&g[2][2]==1) return "A";
                if (g[0][0]==1&&g[1][0]==1&&g[2][0]==1) return "A";
                if (g[0][1]==1&&g[1][1]==1&&g[2][1]==1) return "A";
                if (g[0][2]==1&&g[1][2]==1&&g[2][2]==1) return "A";
            }
            else
            {
                g[m[i][0]][m[i][1]]=2;
                if (g[0][0]==2&&g[1][1]==2&&g[2][2]==2) return "B";
                if (g[0][2]==2&&g[1][1]==2&&g[2][0]==2) return "B";
                if (g[0][0]==2&&g[0][1]==2&&g[0][2]==2) return "B";
                if (g[1][0]==2&&g[1][1]==2&&g[1][2]==2) return "B";
                if (g[2][0]==2&&g[2][1]==2&&g[2][2]==2) return "B";
                if (g[0][0]==2&&g[1][0]==2&&g[2][0]==2) return "B";
                if (g[0][1]==2&&g[1][1]==2&&g[2][1]==2) return "B";
                if (g[0][2]==2&&g[1][2]==2&&g[2][2]==2) return "B";
            }
            if (i==8) return "Draw";
        }
        return "Pending";
    }
};
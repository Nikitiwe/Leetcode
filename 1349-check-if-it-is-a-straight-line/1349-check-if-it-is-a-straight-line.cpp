class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        bool isx=1, isy=1;
        unordered_set<int> m;
        m.insert(c[0][1]);
        for (int i=0; i<c.size()-1; i++)
        {
            if (c[i][0]!=c[i+1][0]) isx=0;
            if (c[i][1]!=c[i+1][1]) isy=0;
            m.insert(c[i+1][1]);
        }
        if (isx==1||isy==1) return 1;
        else if (m.size()<c.size()) return 0;
        else
        {
            double k=(double)(c[0][0]-c[1][0])/(c[0][1]-c[1][1]);
            for (int i=1; i<c.size()-1; i++)
            {
                if (abs((double)(c[i][0]-c[i+1][0])/(c[i][1]-c[i+1][1])-k)>0.00000001) return 0;
            }
        }
        return 1;
    }
};
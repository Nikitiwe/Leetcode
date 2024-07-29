class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> t(obstacles.size(), 0), m(obstacles.size(), 0), b(obstacles.size(), 0);
        t[0]=1;
        b[0]=1;
        for (int i=1; i!=obstacles.size(); i++)
        {
            if (obstacles[i]==0)
            {
                t[i]=t[i-1];
                m[i]=m[i-1];
                b[i]=b[i-1];
                t[i]=min(t[i], min(m[i], b[i])+1);
                m[i]=min(m[i], min(t[i], b[i])+1);
                b[i]=min(b[i], min(t[i], m[i])+1);
            }
            else if (obstacles[i]==1)
            {
                t[i]=999999;
                m[i]=m[i-1];
                b[i]=b[i-1];
                m[i]=min(m[i], min(t[i], b[i])+1);
                b[i]=min(b[i], min(t[i], m[i])+1);
            }
            else if (obstacles[i]==2)
            {
                t[i]=t[i-1];
                m[i]=999999;
                b[i]=b[i-1];
                t[i]=min(t[i], min(m[i], b[i])+1);
                b[i]=min(b[i], min(t[i], m[i])+1);
            }
            else
            {
                t[i]=t[i-1];
                m[i]=m[i-1];
                b[i]=999999;
                t[i]=min(t[i], min(m[i], b[i])+1);
                m[i]=min(m[i], min(t[i], b[i])+1);
            }
        }
        return min({t[obstacles.size()-1], m[obstacles.size()-1], b[obstacles.size()-1]});
    }
};
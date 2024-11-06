class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int ans=0;
        for (int i=0; i!=p.size(); i++)
        {
            unordered_map<int, int> m;
            for (int j=0; j!=p.size(); j++)
            {
                int t=(p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
                if (m.count(t)>0) ans+=m[t];
                m[t]++;
            }
        }
        return 2*ans;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<float> tan;
        int vert, ans=0, m, count;
        if (points.size()==2) return 2;
        for (int i=0; i!=points.size()-1; i++)
        {
            vert=0; count=1, m=1;
            tan.clear();
            for (int j=i+1; j!=points.size(); j++)
            {
                if (points[i][1]==points[j][1]) vert++;
                else tan.push_back((float(points[i][0])-float(points[j][0]))/(float(points[i][1])-float(points[j][1])));
            }
            sort(tan.begin(), tan.end());
            for (int j=1; j<tan.size(); j++)
            {
                if (tan[j]==tan[j-1]) {count++; if (count>m) m=count;}
                else {if (count>m) m=count; count=1;}
            }
            m=max(m, vert);
            if (ans<m) ans=m;
        }
        return ans+1;
    }
};
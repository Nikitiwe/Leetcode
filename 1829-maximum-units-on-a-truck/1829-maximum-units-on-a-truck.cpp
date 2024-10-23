bool sorrt (vector<int> x, vector<int> y)
{
    return x[1]<y[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(), b.end(), sorrt);
        int ans=0, i=b.size()-1;
        while (t>0&&i>=0)
        {
            if (b[i][0]<=t)
            {
                ans+=b[i][0]*b[i][1];
                t-=b[i][0];
                i--;
            }
            else
            {
                ans+=t*b[i][1];
                t-=b[i][0];
                i--;
            }
        }
        return ans;
    }
};
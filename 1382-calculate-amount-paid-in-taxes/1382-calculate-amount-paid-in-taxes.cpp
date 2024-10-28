class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int a) {
        double ans=0;
        if (a>=b[0][0]) ans+=(double)b[0][0]*b[0][1]/100;
        else ans+=(double)(a)*b[0][1]/100;
        if (a>b[0][0]) for (int i=1; i<b.size(); i++)
        {
            if (a>=b[i][0]) ans+=(double)(b[i][0]-b[i-1][0])*b[i][1]/100;
            else
            {
                ans+=(double)(a-b[i-1][0])*b[i][1]/100;
                break;
            }
        }
        return ans;
    }
};
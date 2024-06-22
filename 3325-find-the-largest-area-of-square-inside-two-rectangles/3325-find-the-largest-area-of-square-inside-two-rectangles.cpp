class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long deltax, deltay, ans=0;
        for (int i=0; i!=bottomLeft.size()-1; i++)
        {
            for (int j=i+1; j!=bottomLeft.size(); j++)
            {
                deltax=min(topRight[i][0],topRight[j][0])-max(bottomLeft[i][0],bottomLeft[j][0]);
                if (deltax>0)
                {
                    deltay=min(topRight[i][1],topRight[j][1])-max(bottomLeft[i][1],bottomLeft[j][1]);
                    if (deltay>0) {if (ans<min(deltax,deltay)) ans=min(deltax,deltay);}
                }
            }
        }
        return ans*ans;
    }
};
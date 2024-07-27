class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0, a=startPos[0], b=homePos[0];
        if (a<=b)
        for (int i=a+1; i<=b; i++)
        {
            ans+=rowCosts[i];
        }
        else for (int i=a-1; i>=b; i--)
        {
            ans+=rowCosts[i];
        }
        a=startPos[1]; b=homePos[1];
        if (a<=b)
        for (int i=a+1; i<=b; i++)
        {
            ans+=colCosts[i];
        }
        else for (int i=a-1; i>=b; i--)
        {
            ans+=colCosts[i];
        }
        return ans;
    }
};
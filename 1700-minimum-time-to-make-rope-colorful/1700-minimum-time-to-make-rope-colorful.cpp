class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0, m=0;
        for (int i=0; i!=colors.size(); i++)
        {
            ans+=neededTime[i];
            m=max(m, neededTime[i]);
            if (i<colors.size()-1&&colors[i]==colors[i+1]) continue;
            else
            {
                ans-=m;
                m=0;
            }
        }
        return ans;
    }
};
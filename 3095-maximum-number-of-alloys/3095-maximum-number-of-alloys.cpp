class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans=0, temp=0;
        for (int i=0; i!=composition.size(); i++)
        {
            temp=0;
            long l=0, r=2000000000, m=(l+r)/2, s=0;
            while (l<r)
            {
                s=0;
                for (int j=0; j!=stock.size(); j++)
                {
                    if (m*composition[i][j]>stock[j]) s+=(m*composition[i][j]-stock[j])*cost[j];
                }
                if (s>budget) {r=m-1; m=(l+r)/2;}
                else if (s<=budget) {l=m+1; m=(l+r)/2;}
            }
            s=0;
            for (int j=0; j!=stock.size(); j++)
            {
                if (m*composition[i][j]>stock[j]) s+=(m*composition[i][j]-stock[j])*cost[j];
            }
            if (s>budget) m--;
            
            temp=m;
            ans=max(ans, temp);
        }
        return ans;
    }
};
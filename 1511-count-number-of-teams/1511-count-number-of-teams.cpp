class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        for (int i=0; i!=rating.size()-2; i++)
        {
            for (int j=i+1; j!=rating.size()-1; j++)
            {
                if (rating[i]>rating[j])
                for (int k=j+1; k!=rating.size(); k++)
                {
                    if (rating[j]>rating[k]) ans++;
                }
                else
                for (int k=j+1; k!=rating.size(); k++)
                {
                    if (rating[j]<rating[k]) ans++;
                }
            }
        }
        return ans;
    }
};
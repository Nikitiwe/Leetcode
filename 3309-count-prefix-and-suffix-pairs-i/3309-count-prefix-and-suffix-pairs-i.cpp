class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& w) {
        int ans=0;
        for (int i=0; i<w.size()-1; i++)
        {
            for (int j=i+1; j<w.size(); j++)
            {
                if (w[i].size()<=w[j].size())
                {
                    bool l=1, r=1;
                    for (int a=0; a<w[i].size(); a++)
                    {
                        if (w[i][a]!=w[j][a])
                        {
                            l=0;
                            break;
                        }
                    }
                    if (l==1)
                    {
                        for (int a=0; a<w[i].size(); a++)
                        {
                            if (w[i][w[i].size()-1-a]!=w[j][w[j].size()-1-a])
                            {
                                r=0;
                                break;
                            }
                        }
                        if (r==1) ans++;
                    }
                }
            }
        }
        return ans;
    }
};
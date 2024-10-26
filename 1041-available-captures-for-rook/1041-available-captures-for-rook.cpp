class Solution {
public:
    int numRookCaptures(vector<vector<char>>& b) {
        int x, y;
        for (int i=0; i!=b.size(); i++)
        {
            for (int j=0; j!=b[0].size(); j++)
            {
                if (b[i][j]=='R')
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        int l=1, ans=0;
        while (x+l<b.size())
        {
            if (b[x+l][y]=='p')
            {
                ans++;
                break;
            }
            else if (b[x+l][y]=='B') break;
            else l++;
        }
        l=-1;
        while (x+l>=0)
        {
            if (b[x+l][y]=='p')
            {
                ans++;
                break;
            }
            else if (b[x+l][y]=='B') break;
            else l--;
        }
        l=1;
        while (y+l<b[0].size())
        {
            if (b[x][y+l]=='p')
            {
                ans++;
                break;
            }
            else if (b[x][y+l]=='B') break;
            else l++;
        }
        l=-1;
        while (y+l>=0)
        {
            if (b[x][y+l]=='p')
            {
                ans++;
                break;
            }
            else if (b[x][y+l]=='B') break;
            else l--;
        }
        return ans;
    }
};
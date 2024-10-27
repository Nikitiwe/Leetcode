class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& s) {
        vector<vector<int>> ans=s;

        if (s.size()>1&&s[0].size()>1)
        {
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=0; j!=s[0].size(); j++)
            {
                ans[i+1][j]+=s[i][j];
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i][j+1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=0; j!=s[0].size(); j++)
            {
                ans[i-1][j]+=s[i][j];
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i][j-1]+=s[i][j];
            }
        }
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i+1][j+1]+=s[i][j];
            }
        }
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i+1][j-1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i-1][j+1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i-1][j-1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size()-1; i++)
        {
            ans[i][0]/=6;
            ans[i][s[0].size()-1]/=6;
        }
        for (int j=1; j<s[0].size()-1; j++)
        {
            ans[0][j]/=6;
            ans[s.size()-1][j]/=6;
        }
        for (int i=1; i<s.size()-1; i++)
        {
            for (int j=1; j<s[0].size()-1; j++)
            {
                ans[i][j]/=9;
            }
        }
        ans[0][0]/=4;
        ans[s.size()-1][s[0].size()-1]/=4;
        ans[s.size()-1][0]/=4;
        ans[0][s[0].size()-1]/=4;
        }

        else if (s.size()>1&&s[0].size()==1)
        {
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=0; j!=s[0].size(); j++)
            {
                ans[i+1][j]+=s[i][j];
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i][j+1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=0; j!=s[0].size(); j++)
            {
                ans[i-1][j]+=s[i][j];
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i][j-1]+=s[i][j];
            }
        }
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i+1][j+1]+=s[i][j];
            }
        }
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i+1][j-1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i-1][j+1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i-1][j-1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size()-1; i++)
        {
            ans[i][0]/=3;
        }
        ans[0][0]/=2;
        ans[s.size()-1][0]/=2;
        }

        else if (s.size()==1&&s[0].size()>1)
        {
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=0; j!=s[0].size(); j++)
            {
                ans[i+1][j]+=s[i][j];
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i][j+1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=0; j!=s[0].size(); j++)
            {
                ans[i-1][j]+=s[i][j];
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i][j-1]+=s[i][j];
            }
        }
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i+1][j+1]+=s[i][j];
            }
        }
        for (int i=0; i<s.size()-1; i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i+1][j-1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=0; j<s[0].size()-1; j++)
            {
                ans[i-1][j+1]+=s[i][j];
            }
        }
        for (int i=1; i<s.size(); i++)
        {
            for (int j=1; j<s[0].size(); j++)
            {
                ans[i-1][j-1]+=s[i][j];
            }
        }
        for (int i=1; i<s[0].size()-1; i++)
        {
            ans[0][i]/=3;
        }
        ans[0][0]/=2;
        ans[0][s[0].size()-1]/=2;
        }
        return ans;
    }
};
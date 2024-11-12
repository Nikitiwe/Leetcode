class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for (int i=0; i!=d.size(); i++)
        {
            if (ans.size()<=d[i].size())
            {
            int l=0, r=0;
            while (l<s.size()&&r<d[i].size())
            {
                if (s[l]==d[i][r])
                {
                    l++;
                    r++;
                }
                else
                {
                    l++;
                }
                if (r==d[i].size())
                {
                    if (ans.size()<d[i].size()) ans=d[i];
                    else if (ans.size()==d[i].size()) ans=min(ans, d[i]);
                }
            }
            }
        }
        return ans;
    }
};
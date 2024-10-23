class Solution {
public:
    int countPrefixes(vector<string>& w, string s) {
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            if (w[i].size()<=s.size())
            {
                bool isit=1;
                int l=0;
                while (l<w[i].size()&&w[i][l]==s[l])
                {
                    l++;
                }
                if (l==w[i].size()) ans++;
            }
        }
        return ans;
    }
};
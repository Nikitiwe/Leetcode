class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string, string> m;
        for (int i=0; i!=k.size(); i++) m[k[i][0]]=k[i][1];
        int l=0;
        string ans;
        while (l<s.size())
        {
            if (s[l]!='(')
            {
                ans+=s[l];
                l++;
            }
            else
            {
                l++;
                string t;
                while (s[l]!=')')
                {
                    t+=s[l];
                    l++;
                }
                l++;
                if (m.count(t)>0) ans+=m[t];
                else ans+="?";
            }
        }
        return ans;
    }
};
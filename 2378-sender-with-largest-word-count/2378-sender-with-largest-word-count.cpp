class Solution {
public:
    string largestWordCount(vector<string>& s, vector<string>& w) {
        //return max("OXlq", "FnZd");;
        unordered_map<string, int> m;
        int ma=0;
        for (int i=0; i!=s.size(); i++)
        {
            int t=0;
            for (int j=0; j!=s[i].size(); j++)
            {
                if (s[i][j]==' ') t++;
            }
            m[w[i]]+=t+1;
            ma=max(ma, m[w[i]]);
        }
        //return to_string(ma);
        string ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==ma) ans=max(ans, i->first);
        }
        return ans;
    }
};
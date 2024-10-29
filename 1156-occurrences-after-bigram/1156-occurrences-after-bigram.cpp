class Solution {
public:
    vector<string> findOcurrences(string s, string w1, string w2) {
        vector<string> ans;
        s+=' ';
        string t, x, y;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ') t+=s[i];
            else
            {
                if (x==w1&&y==w2) ans.push_back(t);
                x=y;
                y=t;
                t="";
            }
        }
        return ans;
    }
};
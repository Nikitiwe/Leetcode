class Solution {
public:
    int numUniqueEmails(vector<string>& s) {
        unordered_set<string> m;
        for (int i=0; i!=s.size(); i++)
        {
            string a, b;
            int l=0;
            while (l<s[i].size())
            {
                if (s[i][l]=='+'||s[i][l]=='@') break;
                if (s[i][l]!='.') a+=s[i][l];
                l++;
            }
            l=0;
            while (s[i][l]!='@') l++;
            l++;
            while (l<s[i].size())
            {
                b+=s[i][l];
                l++;
            }
            m.insert(a+'@'+b);
        }
        return m.size();
    }
};
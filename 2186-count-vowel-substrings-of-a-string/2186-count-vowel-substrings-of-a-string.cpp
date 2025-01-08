class Solution {
public:
    int countVowelSubstrings(string s) {
        int ans=0;
        for (int k=0; k!=s.size(); k++)
        {
            bool a=0, e=0, o=0, u=0, i=0;
            for (int j=k; j<s.size(); j++)
            {
                if (s[j]!='a'&&s[j]!='e'&&s[j]!='u'&&s[j]!='i'&&s[j]!='o') break;
                else if (s[j]=='a') a=1;
                else if (s[j]=='e') e=1;
                else if (s[j]=='u') u=1;
                else if (s[j]=='i') i=1;
                else if (s[j]=='o') o=1;
                if (a&&e&&u&&i&&o) ans++;
            }
        }
        return ans;
    }
};
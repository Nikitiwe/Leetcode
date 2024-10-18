class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        int r=s.size()-1;
        while (r>=0)
        {
            if (s[r]=='#')
            {
                int t=0;
                r--;
                t+=s[r]-'0';
                r--;
                t+=10*(s[r]-'0');
                ans+=t+'a'-1;
                r--;
            }
            else
            {
                ans+=s[r]-'0'+'a'-1;
                r--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
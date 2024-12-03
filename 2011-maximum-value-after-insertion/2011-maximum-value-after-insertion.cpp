class Solution {
public:
    string maxValue(string s, int x) {
        string ans;
        if (s[0]!='-')
        {
            for (int i=0; i!=s.size(); i++)
            {
                if (x>s[i]-'0')
                {
                    ans+=to_string(x);
                    x=-1;
                }
                ans+=s[i];
            }
        }
        else
        {
            ans+='-';
            for (int i=1; i<s.size(); i++)
            {
                if (x<s[i]-'0')
                {
                    ans+=to_string(x);
                    x=10;
                }
                ans+=s[i];
            }
        }
        if (x!=-1&&x!=10) ans+=to_string(x);
        return ans;
    }
};
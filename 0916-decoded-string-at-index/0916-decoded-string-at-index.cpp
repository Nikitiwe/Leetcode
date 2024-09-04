class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long l=0;
        string ans;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='a'&&s[i]<='z') l++;
            else l*=(s[i]-'0');
        }
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]>='a'&&s[i]<='z')
            {
                l--;
                if (k>l)
                {
                    ans+=s[i];
                    return ans;
                }
            }
            else
            {
                l/=(s[i]-'0');
                while (k>l) k-=l;
            }
        }
        return "-1";
    }
};
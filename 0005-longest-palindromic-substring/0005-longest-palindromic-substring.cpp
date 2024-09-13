class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        ans+=s[0];
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=s.size()-1; j>=i+ans.size(); j--)
            {
                bool isit=1;
                for (int a=0; a<=(j-i)/2; a++)
                {
                    if (s[i+a]!=s[j-a]) {isit=0; break;}
                }
                if (isit==1&&j-i+1>ans.size()) ans=s.substr(i, j-i+1);
            }
        }
        return ans;
    }
};
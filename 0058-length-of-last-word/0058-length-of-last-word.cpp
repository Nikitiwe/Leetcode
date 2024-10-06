class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool isit=1;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]==' '&&isit==1) continue;
            else if (s[i]!=' ')
            {
                ans++;
                isit=0;
            }
            else break;
        }
        return ans;
    }
};
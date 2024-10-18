class Solution {
public:
    int countAsterisks(string s) {
        int ans=0, c=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='|') c^=1;
            else if (s[i]=='*'&&c==0) ans++;
        }
        return ans;
    }
};
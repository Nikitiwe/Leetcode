class Solution {
public:
    int countAsterisks(string s) {
        int ans=0, c=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='|') c++;
            else if (s[i]=='*'&&c%2==0) ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int percentageLetter(string s, char l) {
        int ans=0;
        for (int i=0; i!=s.size(); i++) if (s[i]==l) ans++;
        return ans*100/s.size();
    }
};
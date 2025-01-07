class Solution {
public:
    int convertTime(string s, string t) {
        int a=(s[0]-'0')*600+(s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0'),
            b=(t[0]-'0')*600+(t[1]-'0')*60+(t[3]-'0')*10+(t[4]-'0');
        int ans=0, d=b-a;
        ans+=d/60;
        d%=60;
        ans+=d/15;
        d%=15;
        ans+=d/5;
        d%=5;
        ans+=d;
        return ans;
    }
};
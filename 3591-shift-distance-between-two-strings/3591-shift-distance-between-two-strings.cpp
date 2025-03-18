class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& n, vector<int>& p) {
        long long ans = 0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == t[i]) continue;
            long long r = 0, l = 0;
            for (int j = 0; ; j++)
            {
                if (((s[i]-'a'+j)%26+26)%26 == t[i] - 'a') break;
                r += n[((s[i]-'a'+j)%26+26)%26];
            }
            for (int j = 0; ; j++)
            {
                if (((s[i]-'a'-j)%26+26)%26 == t[i] - 'a') break;
                l += p[((s[i]-'a'-j)%26+26)%26];
            }
            ans += min(l, r);
        }
        return ans;
    }
};
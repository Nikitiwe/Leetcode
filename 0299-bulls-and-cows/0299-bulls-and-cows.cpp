class Solution {
public:
    string getHint(string s, string g) {
        int ans1=0, ans2=0;
        vector<int> a(10, 0), b(10, 0);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==g[i]) ans1++;
            else
            {
                a[s[i]-'0']++;
                b[g[i]-'0']++;
            }
        }
        for (int i=0; i!=10; i++)
        {
            ans2+=min(a[i], b[i]);
        }
        return to_string(ans1)+'A'+to_string(ans2)+'B';
    }
};
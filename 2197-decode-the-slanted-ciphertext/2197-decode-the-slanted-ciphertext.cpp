class Solution {
public:
    string decodeCiphertext(string s, int n) {
        if (s.size()==0) return "";
        string ans;
        int k=s.size()/n, c=0, sum=0;
        for (int i=0; i<=k-n+1; i++)
        {
            c=i;
            for (int j=0; j!=n; j++)
            {
                ans+=s[c%s.size()];
                c+=k+1;
            }
        }
        ans.pop_back();
        while (ans.back()==' ') ans.pop_back();
        return ans;
    }
};
class Solution {
public:
    string convert(string s, int n) {
        if (n==1) return s;
        vector<string> ans(min(n, (int)s.size()), "");
        int temp, k=2*n-2;
        for (int i=0; i!=s.size(); i++)
        {
            temp=i%k;
            if (temp<n) ans[temp]+=s[i];
            else ans[k-temp]+=s[i];
        }
        s="";
        for (int i=0; i!=ans.size(); i++)
        {
            s+=ans[i];
        }
        return s;
    }
};
class Solution {
public:
    string convert(string s, int n) {
        if (n==1) return s;
        vector<string> ans(min(n, (int)s.size()), "");
        int temp;
        for (int i=0; i!=s.size(); i++)
        {
            temp=i%(2*n-2);
            if (temp<n) ans[temp]+=s[i];
            else ans[2*n-2-temp]+=s[i];
        }
        s="";
        for (int i=0; i!=ans.size(); i++)
        {
            s+=ans[i];
        }
        return s;
    }
};
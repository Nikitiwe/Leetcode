class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        vector<int> v(s.size()+1, 0), c(s.size()+1, 0);
        int a=0, b=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') a++;
            else b++;
            v[i+1]=a;
            c[i+1]=b;
        }
        int ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=i+1; j<s.size(); j++)
            {
                if (v[j+1]-v[i]==c[j+1]-c[i]) if ((v[j+1]-v[i])*(v[j+1]-v[i])%k==0) ans++;
            }
        }
        return ans;
    }
};
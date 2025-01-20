class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int i=1; i<=3; i++)
        {
            for (int j=1; j<=3; j++)
            {
                for (int k=1; k<=3; k++)
                {
                    for (int l=1; l<=3; l++)
                    {
                        if (s.size()!=i+j+k+l) continue;
                        string t;
                        int a=0;
                        for (int n=0; n<i; n++)
                        {
                            a*=10;
                            a+=s[n]-'0';
                        }
                        if (a>255||size(to_string(a))!=i) continue;
                        t+=to_string(a)+'.';
                        a=0;
                        for (int n=0; n<j; n++)
                        {
                            a*=10;
                            a+=s[i+n]-'0';
                        }
                        if (a>255||size(to_string(a))!=j) continue;
                        t+=to_string(a)+'.';
                        a=0;
                        for (int n=0; n<k; n++)
                        {
                            a*=10;
                            a+=s[i+j+n]-'0';
                        }
                        if (a>255||size(to_string(a))!=k) continue;
                        t+=to_string(a)+'.';
                        a=0;
                        for (int n=0; n<l; n++)
                        {
                            a*=10;
                            a+=s[i+j+k+n]-'0';
                        }
                        if (a>255||size(to_string(a))!=l) continue;
                        t+=to_string(a);
                        ans.push_back(t);
                    }
                }
            }
        }
        return ans;
    }
};
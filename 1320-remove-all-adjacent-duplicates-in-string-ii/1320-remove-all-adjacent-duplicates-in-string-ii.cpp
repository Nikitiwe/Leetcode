class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        int f;
        ans.push_back(s[0]);
        if (s.size()>0) ans.push_back(s[1]);
        for (int i=2; i!=s.size(); i++)
        {
            f=1;
            ans.push_back(s[i]);
            while (f==1)
            {
                if (ans.size()>=k)
                {
                    f=1;
                    for (int j=0; j!=k-1; j++)
                    {
                        if (ans[ans.size()-1-j]!=ans[ans.size()-2-j]) {f=0; break;}
                    }
                    if (f==1)
                    {
                        for (int j=0; j!=k; j++)
                        {
                            ans.erase(ans.begin()+ans.size()-1);
                        }
                    }
                }
                else break;
            }
        }
        return ans;
    }
};
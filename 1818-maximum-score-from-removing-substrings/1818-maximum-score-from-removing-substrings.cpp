class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        string a, b;
        if (x>=y)
        {
            for (int j=0; j!=s.size(); j++)
            {
                a.push_back(s[j]);
                if (a.size()>1&&a[a.size()-1]=='b'&&a[a.size()-2]=='a')
                {
                    a.erase(a.size()-2, 2);
                    ans+=x;
                }
            }

            for (int j=0; j!=a.size(); j++)
            {
                b.push_back(a[j]);
                if (b.size()>1&&b[b.size()-1]=='a'&&b[b.size()-2]=='b')
                {
                    b.erase(b.size()-2, 2);
                    ans+=y;
                }
            }
        }
        else
        {
            for (int j=0; j!=s.size(); j++)
            {
                a.push_back(s[j]);
                if (a.size()>1&&a[a.size()-1]=='a'&&a[a.size()-2]=='b')
                {
                    a.erase(a.size()-2, 2);
                    ans+=y;
                }
            }

            for (int j=0; j!=a.size(); j++)
            {
                b.push_back(a[j]);
                if (b.size()>1&&b[b.size()-1]=='b'&&b[b.size()-2]=='a')
                {
                    b.erase(b.size()-2, 2);
                    ans+=x;
                }
            }
        }
        return ans;
    }
};
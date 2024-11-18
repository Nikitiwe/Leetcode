class Solution {
public:
    string removeDigit(string n, char d) {
        bool isit=0;
        string ans;
        for (int i=0; i<n.size()-1; i++)
        {
            if (isit==0&&n[i]==d&&n[i+1]>n[i])
            {
                isit=1;
            }
            else ans+=n[i];
        }
        ans+=n[n.size()-1];
        if (isit==0)
        {
            int id;
            for (int i=n.size()-1; i>=0; i--)
            {
                if (n[i]==d)
                {
                    id=i;
                    break;
                }
            }
            ans="";
            for (int i=0; i<n.size(); i++)
            {
                if (i!=id) ans+=n[i];
            }
        }
        return ans;
    }
};
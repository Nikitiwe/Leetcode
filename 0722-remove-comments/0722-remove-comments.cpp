class Solution {
public:
    vector<string> removeComments(vector<string>& s) {
        vector<string> ans;
        int a=0;
        string t;
        for (int i=0; i!=s.size(); i++)
        {
            int l=0;
            if (a==0) t="";
            while (l<s[i].size())
            {
                if (a==0)
                {
                    if (s[i][l]!='/')
                    {
                        t+=s[i][l];
                        l++;
                    }
                    else if (l<s[i].size()-1&&s[i][l+1]=='/') break;
                    else if (l<s[i].size()-1&&s[i][l+1]=='*') {a=1; l+=2;}
                    else
                    {
                        t+=s[i][l];
                        l++;
                    }
                }
                else
                {
                    if (s[i][l]!='*') l++;
                    else if (l<s[i].size()-1&&s[i][l+1]=='/') {a=0; l+=2;}
                    else l++;
                }
            }
        if (a==0&&t.size()>0) ans.push_back(t);
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> printVertically(string s) {
        int max=0, temp=0, j=0;
        vector<string> s1;
        s1.push_back("");
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ') {s1[j].push_back(s[i]); temp++; if (i==s.size()-1) if (temp>max) max=temp;}
            else {if (temp>max) max=temp; temp=0; j++; s1.push_back("");}
        }
        vector<string> ans(max, "");
        for (int i=0; i!=s1.size(); i++)
        {
            for (int j=0; j!=max; j++)
            {
                if (j<s1[i].size()) ans[j]=ans[j]+s1[i][j];
                else ans[j]=ans[j]+" ";
            }
        }
        for (int i=0; i!=max; i++)
        {
            for (int j=ans[i].size()-1; j>=0; j--)
            {
                if (ans[i][j]==' ') ans[i].pop_back();
                else break;
            }
        }
        return ans;
    }
};
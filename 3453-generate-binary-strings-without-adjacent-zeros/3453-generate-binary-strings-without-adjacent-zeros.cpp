class Solution {
public:
    vector<string> validStrings(int n) {
        int s, isit;
        vector<string> ans, prev{"0","1"};
        string t;
        if (n==1) return {"0","1"};
        for (int i=1; i!=n; i++)
        {
            for (int j=0; j!=prev.size(); j++)
            {
                if (prev[j][prev[j].size()-1]=='0')
                {
                    t.clear();
                    t=prev[j]+'1';
                    ans.push_back(t);
                }
                else
                {
                    t.clear();
                    t=prev[j]+'1';
                    ans.push_back(t);
                    t.clear();
                    t=prev[j]+'0';
                    ans.push_back(t);
                }
            }
            prev=ans;
            ans.clear();
        }
        return prev;

    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<unordered_set<string>> arr(n+1, unordered_set<string> ());
        arr[1].insert("()");
        for (int i=2; i<=n; i++)
        {
            for (auto j=arr[i-1].begin(); j!=arr[i-1].end(); j++)
            {
                string t="(";
                t+=*j+")";
                arr[i].insert(t);
            }
            for (int k=1; k<i; k++)
            {
                for (auto j=arr[k].begin(); j!=arr[k].end(); j++)
                {
                    string t=*j;
                    for (auto a=arr[i-k].begin(); a!=arr[i-k].end(); a++)
                    {
                        string tt=t;
                        tt+=*a;
                        arr[i].insert(tt);
                    }
                }
            }
        }
        vector<string> ans;
        for (auto j=arr[n].begin(); j!=arr[n].end(); j++) ans.push_back(*j);
        return ans;
    }
};
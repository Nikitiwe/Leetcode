class Solution {
public:
    vector<string> wordSubsets(vector<string>& s, vector<string>& w) {
        vector<bool> isit(s.size(), 1);
        unordered_set<string> m;
        for (int i=0; i!=w.size(); i++) m.insert(w[i]);
        vector<vector<int>> arr(s.size(), vector<int> (26, 0));
        vector<int> t(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=0; j!=s[i].size(); j++) arr[i][s[i][j]-'a']++;
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            vector<int> tt(26, 0);
            string a=*i;
            for (int j=0; j!=a.size(); j++) tt[a[j]-'a']++;
            for (int j=0; j!=26; j++) t[j]=max(t[j], tt[j]);
            
        }
            for (int j=0; j!=s.size(); j++)
            {
                    for (int k=0; k!=26; k++)
                    {
                        if (t[k]>arr[j][k])
                        {
                            isit[j]=0;
                            break;
                        }
                    }
            }
        vector<string> ans;
        for (int j=0; j!=s.size(); j++)
        {
            if (isit[j]==1) ans.push_back(s[j]);
        }
        return ans;
    }
};
// Time Limit Exceeded 47/56 testcases passed
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        vector<string> ans;
        unordered_set<string> m;
        for (int i=0; i!=f.size(); i++)
        {
            m.insert(f[i]);
        }
        for (int i=0; i!=f.size(); i++)
        {
            string t=f[i];
            bool isit=1;
            while (t.size()>0)
            {
                while (t[t.size()-1]!='/') t.pop_back();
                t.pop_back();
                if (m.count(t)==1)
                {
                    isit=0;
                    break;
                }
                if (isit==0) break;
            }
            if (isit==1) ans.push_back(f[i]);
        }
        return ans;
    }
};
bool ssort (string a, string b)
{
    return a.size()<b.size();
}

class Solution {
public:
    string longestWord(vector<string>& w) {
        unordered_map<string, int> m;
        sort(w.begin(), w.end(), ssort);
        string ans;
        for (int i=0; i!=w.size(); i++)
        {
            if (w[i].size()==1) m[w[i]]=1;
            else
            {
                string t=w[i];
                t.pop_back();
                if (m.count(t)>0)
                {
                    m[w[i]]=m[t]+1;
                }
            }
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==ans.size()) ans=min(ans, i->first);
            else if (i->second>ans.size()) ans=i->first;
        }
        return ans;
    }
};
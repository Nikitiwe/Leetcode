class Solution {
public:
    vector<int> topStudents(vector<string>& pp, vector<string>& nn, vector<string>& s, vector<int>& id, int k) {
        unordered_set<string> p(pp.begin(), pp.end()), n(nn.begin(), nn.end());
        priority_queue<long> q;
        unordered_map<long, int> m;
        for (int i=0; i!=s.size(); i++)
        {
            long a=0;
            string t;
            int l=0;
            s[i]+=' ';
            while (l<s[i].size())
            {
                if (s[i][l]!=' ') t+=s[i][l];
                else
                {
                    if (p.count(t)>0) a+=3;
                    else if (n.count(t)>0) a--;
                    t="";
                }
                l++;
            }
            a*=10000000000;
            a-=id[i];
            q.push(a);
            m[a]=id[i];
        }
        vector<int> ans(k, 0);
        for (int i=0; i!=k; i++)
        {
            ans[i]=m[q.top()];
            q.pop();
        }
        return ans;
    }
};
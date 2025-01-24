class Solution {
public:
    int minMutation(string a, string b, vector<string>& s) {
        queue<string> q;
        q.push(a);
        unordered_map<string, int> m;
        for (int i=0; i!=s.size(); i++) m[s[i]]=100000;
        m[a]=0;
        if (m.count(b)==0) return -1;
        while (q.size()>0)
        {
            string t;
            for (int i=0; i!=8; i++)
            {
                t=q.front();
                t[i]='A';
                if (t!=q.front()&&m.count(t)>0&&m[t]>m[q.front()]+1)
                {
                    m[t]=m[q.front()]+1;
                    q.push(t);
                }
                t=q.front();
                t[i]='C';
                if (t!=q.front()&&m.count(t)>0&&m[t]>m[q.front()]+1)
                {
                    m[t]=m[q.front()]+1;
                    q.push(t);
                }
                t=q.front();
                t[i]='G';
                if (t!=q.front()&&m.count(t)>0&&m[t]>m[q.front()]+1)
                {
                    m[t]=m[q.front()]+1;
                    q.push(t);
                }
                t=q.front();
                t[i]='T';
                if (t!=q.front()&&m.count(t)>0&&m[t]>m[q.front()]+1)
                {
                    m[t]=m[q.front()]+1;
                    q.push(t);
                }
            }
            q.pop();
        }
        if (m[b]<100000) return m[b];
        else return -1;
    }
};
class Solution {
public:
    void prishel(queue<int> &q, vector<int>& p, int &j, int m, bool &sel)
    {
        if (sel == 0 && p[j] >= m)
        {
            q.push(m);
            sel = 1;
        }
        q.push(p[j]);
        j++;                        
    }

    void poehal(queue<int> &q, vector<int>& b, int &i, int m, bool &isit, int n)
    {
        for (int c = 0; c < n; c++)
        {
            if (q.size() == 0) break;
            if (q.front() == m) isit = 1;
            q.pop();
        }
        i++;                     
    }

    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int n) {
        unordered_set<int> s(p.begin(), p.end());
        sort(b.begin(), b.end());
        p.push_back(b.back());
        sort(p.begin(), p.end());
        /*bool proverit = 0;
        if (s.count(b.back()) == 0)
        {
            p.push_back(b.back());
            proverit = 1;
        }*/
        int l = 0, r = b.back(), ans = -1, m;
        while (l <= r)
        {
            m = (l+r)/2;
            queue<int> q;
            bool sel = 0, isit = 0;
            int i = 0, j = 0;
            while (i < b.size())
            {
                if (i < b.size() && j < p.size())
                {
                    if (b[i] < p[j]) poehal(q, b, i, m, isit, n);
                    else if (b[i] > p[j]) prishel(q, p, j, m, sel);
                    else
                    {
                        prishel(q, p, j, m, sel);
                        poehal(q, b, i, m, isit, n);
                    }
                }
                else if (i < b.size())
                {
                    poehal(q, b, i, m, isit, n);
                }
            }
            if (isit == 1)
            {
                int mm = m;
                while (s.count(mm) == 1) mm--;
                ans = max(ans, mm);
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};
class Solution {
public:
    int openLock(vector<string>& dd, string tt) {
        unordered_set<int> d;
        for (int i=0; i!=dd.size(); i++) d.insert(stoi(dd[i]));
        queue<int> s;
        s.push(0);
        unordered_map<int, int> m;
        m[0] = 0;
        if (d.count(0) == 1) return -1;
        while (s.size() > 0)
        {
            int t = s.front();
            s.pop();
            if (t%10 != 9 && d.count(t+1) == 0 && (m.count(t+1) == 0 || m[t+1] > m[t]+1) )
            {
                s.push(t+1);
                m[t+1] = m[t] + 1;
            }
            else if (t%10 == 9 && d.count(t-9) == 0 && (m.count(t-9) == 0 || m[t-9] > m[t]+1) )
            {
                s.push(t-9);
                m[t-9] = m[t] + 1;
            }
            if (t%10 != 0 && d.count(t-1) == 0 && (m.count(t-1) == 0 || m[t-1] > m[t]+1) )
            {
                s.push(t-1);
                m[t-1] = m[t] + 1;
            }
            else if (t%10 == 0 && d.count(t+9) == 0 && (m.count(t+9) == 0 || m[t+9] > m[t]+1) )
            {
                s.push(t+9);
                m[t+9] = m[t] + 1;
            }

            if (t%100/10 != 9 && d.count(t+10) == 0 && (m.count(t+10) == 0 || m[t+10] > m[t]+1) )
            {
                s.push(t+10);
                m[t+10] = m[t] + 1;
            }
            else if (t%100/10 == 9 && d.count(t-90) == 0 && (m.count(t-90) == 0 || m[t-90] > m[t]+1) )
            {
                s.push(t-90);
                m[t-90] = m[t] + 1;
            }
            if (t%100/10 != 0 && d.count(t-10) == 0 && (m.count(t-10) == 0 || m[t-10] > m[t]+1) )
            {
                s.push(t-10);
                m[t-10] = m[t] + 1;
            }
            else if (t%100/10 == 0 && d.count(t+90) == 0 && (m.count(t+90) == 0 || m[t+90] > m[t]+1) )
            {
                s.push(t+90);
                m[t+90] = m[t] + 1;
            }

            if (t%1000/100 != 9 && d.count(t+100) == 0 && (m.count(t+100) == 0 || m[t+100] > m[t]+1) )
            {
                s.push(t+100);
                m[t+100] = m[t] + 1;
            }
            else if (t%1000/100 == 9 && d.count(t-900) == 0 && (m.count(t-900) == 0 || m[t-900] > m[t]+1) )
            {
                s.push(t-900);
                m[t-900] = m[t] + 1;
            }
            if (t%1000/100 != 0 && d.count(t-100) == 0 && (m.count(t-100) == 0 || m[t-100] > m[t]+1) )
            {
                s.push(t-100);
                m[t-100] = m[t] + 1;
            }
            else if (t%1000/100 == 0 && d.count(t+900) == 0 && (m.count(t+900) == 0 || m[t+900] > m[t]+1) )
            {
                s.push(t+900);
                m[t+900] = m[t] + 1;
            }

            if (t%10000/1000 != 9 && d.count(t+1000) == 0 && (m.count(t+1000) == 0 || m[t+1000] > m[t]+1) )
            {
                s.push(t+1000);
                m[t+1000] = m[t] + 1;
            }
            else if (t%10000/1000 == 9 && d.count(t-9000) == 0 && (m.count(t-9000) == 0 || m[t-9000] > m[t]+1) )
            {
                s.push(t-9000);
                m[t-9000] = m[t] + 1;
            }
            if (t%10000/1000 != 0 && d.count(t-1000) == 0 && (m.count(t-1000) == 0 || m[t-1000] > m[t]+1) )
            {
                s.push(t-1000);
                m[t-1000] = m[t] + 1;
            }
            else if (t%10000/1000 == 0 && d.count(t+9000) == 0 && (m.count(t+9000) == 0 || m[t+9000] > m[t]+1) )
            {
                s.push(t+9000);
                m[t+9000] = m[t] + 1;
            }
        }
        if (m.count(stoi(tt)) != 0) return m[stoi(tt)];
        else return -1;
    }
};
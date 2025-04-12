class Solution {
public:
    int f(vector<vector<int>> &arr)
    {
        return arr[0][0]*1 + arr[0][1]*7 + arr[0][2]*49 + arr[1][0]*343 + arr[1][1]*2401 + arr[1][2]*16807;
    }

    void g(vector<vector<int>> &t, unordered_map<int, int> &m, stack<vector<vector<int>>> &q, stack<int> &l, int h)
    {
        if (m.count(f(t)) == 0 || m[f(t)] > h + 1)
        {
            q.push(t);
            l.push(h+1);
            m[f(t)] = h+1;
        }
    }

    int slidingPuzzle(vector<vector<int>>& b) {
        int ans = 20;
        vector<vector<int>> k = {{1,2,3}, {4,5,0}};
        unordered_map<int, int> m;
        stack<vector<vector<int>>> q;
        stack<int> l;
        q.push(b);
        l.push(0);
        m[f(b)] = 0;
        while(q.size() > 0)
        {
            vector<vector<int>> t = q.top();
            int h = l.top();
            q.pop();
            l.pop();
            if (t == k)
            {
                ans = min(ans, h);
                //break;
            }
            else if (h + 1 < ans )
            {
                if (t[0][0] == 0)
                {
                    vector<vector<int>> t1 = t;
                    swap(t1[0][0], t1[0][1]);
                    g(t1, m, q, l, h);
                    vector<vector<int>> t2 = t;
                    swap(t2[0][0], t2[1][0]);
                    g(t2, m, q, l, h);
                }
                else if (t[0][1] == 0)
                {
                    vector<vector<int>> t1 = t;
                    swap(t1[0][1], t1[0][0]);
                    g(t1, m, q, l, h);
                    vector<vector<int>> t2 = t;
                    swap(t2[0][1], t2[0][2]);
                    g(t2, m, q, l, h);
                    vector<vector<int>> t3 = t;
                    swap(t3[0][1], t3[1][1]);
                    g(t3, m, q, l, h);
                }
                else if (t[0][2] == 0)
                {
                    vector<vector<int>> t1 = t;
                    swap(t1[0][2], t1[0][1]);
                    g(t1, m, q, l, h);
                    vector<vector<int>> t2 = t;
                    swap(t2[0][2], t2[1][2]);
                    g(t2, m, q, l, h);
                }
                else if (t[1][0] == 0)
                {
                    vector<vector<int>> t1 = t;
                    swap(t1[1][0], t1[1][1]);
                    g(t1, m, q, l, h);
                    vector<vector<int>> t2 = t;
                    swap(t2[1][0], t2[0][0]);
                    g(t2, m, q, l, h);
                }
                else if (t[1][1] == 0)
                {
                    vector<vector<int>> t1 = t;
                    swap(t1[1][1], t1[1][0]);
                    g(t1, m, q, l, h);
                    vector<vector<int>> t2 = t;
                    swap(t2[1][1], t2[1][2]);
                    g(t2, m, q, l, h);
                    vector<vector<int>> t3 = t;
                    swap(t3[1][1], t3[0][1]);
                    g(t3, m, q, l, h);
                }
                else if (t[1][2] == 0)
                {
                    vector<vector<int>> t1 = t;
                    swap(t1[1][2], t1[1][1]);
                    g(t1, m, q, l, h);
                    vector<vector<int>> t2 = t;
                    swap(t2[1][2], t2[0][2]);
                    g(t2, m, q, l, h);
                }
            }
        }
        if (ans < 20) return ans;
        else return -1;
    }
};
class Solution {
public:
    int findCrossingTime(int nn, int k, vector<vector<int>>& arr) {
        priority_queue<pair<int, pair<int, int>>> t; // время + что + id
        priority_queue<pair<int, int>> q, r; // эффективность + id
        for (int i=0; i!=arr.size(); i++)
        {
            q.push({ arr[i][0] + arr[i][2], i});
        }
        // 4 == пошел направо
        // 3 == взял груз
        // 2 == пошел налево
        // 1 == опустил груз
        // 0 == чо происходит, вставляем после другой операции если следующее время другое
        bool b = 0;
        int n = nn;
        int p = 0;
        t.push({ 0, {0, 0}});
        t.push({ - 2000000000, {0, 0}});
        while (t.size() > 0)
        {
            int time = - t.top().first;
            int type = t.top().second.first;
            int id = t.top().second.second;
            t.pop();
            if (type == 4)
            {
                b = 0;
                n--;
                t.push({ - time - arr[id][1], {3, id}});
            }
            else if (type == 3)
            {
                r.push({ arr[id][0] + arr[id][2], id});
            }
            else if (type == 2)
            {
                b = 0;
                p++;
                if (p == nn) return time;
                t.push({ - time - arr[id][3], {1, id}});
            }
            else if (type == 1)
            {
                q.push({ arr[id][0] + arr[id][2], id});
            }
            else if (type == 0)
            {
                //if (p == nn) return time;
                if (b == 0)
                {
                    if (r.size() > 0)
                    {
                        int idt = r.top().second;
                        r.pop();
                        t.push({ - time - arr[idt][2], {2, idt}});
                        b = 1;
                    }
                    else if (q.size() > 0 && n > 0)
                    {
                        int idt = q.top().second;
                        q.pop();
                        t.push({ - time - arr[idt][0], {4, idt}});
                        b = 1;
                    }
                }
            }

            if (type != 0 && - t.top().first != time) t.push({ - time, {0, -1}});
        }
        return -1;
    }
};
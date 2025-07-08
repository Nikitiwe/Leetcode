class Solution {
public:
    int maxValue(vector<vector<int>>& e, int k) {
        priority_queue<tuple<int, int, int, vector<int>>> q; // -время, тип, id, вектор который модифицируем
        // 1 это обновить текущий максимум, 0 это запустить в будущее
        for (int i=0; i!=e.size(); i++)
        {
            q.push({ - e[i][0], 0, i, {}});
        }
        vector<int> ans(k, 0);
        while (q.size() > 0)
        {
            auto [time, type, id, t] = q.top();
            q.pop();
            time *= -1;
            if (type == 1)
            {
                for (int i=k-1; i>=1; i--)
                {
                    t[i] = t[i-1] + e[id][2];
                }
                t[0] = e[id][2]; // это мы вышли из события и готовы обновлять ответ

                for (int i=0; i<k; i++)
                {
                    ans[i] = max(ans[i], t[i]);
                }
            }
            else
            {
                q.push({ - e[id][1] - 1, 1, id, ans});
            }
        }
        //return ans[0];
        int res = 0;
        for (int i=0; i<k; i++)
        {
            res = max(res, ans[i]);
        }
        return res;
    }
};
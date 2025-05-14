class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        vector<long long> l(h.size(), 0), r = l;
        stack<pair<long long, long long>> s; // высота + ширина
        long long sum = 0;
        for (int i=0; i!=h.size(); i++)
        {
            long long w = 1;
            while (s.size() > 0 && s.top().first > h[i])
            {
                sum -= s.top().first * s.top().second;
                w += s.top().second;
                s.pop();
            }
            sum += w * h[i];
            s.push({h[i], w});
            l[i] = sum;
        }
        while(s.size() > 0) s.pop();
        sum = 0;
        for (int i=h.size() - 1; i>=0; i--)
        {
            long long w = 1;
            while (s.size() > 0 && s.top().first > h[i])
            {
                sum -= s.top().first * s.top().second;
                w += s.top().second;
                s.pop();
            }
            sum += w * h[i];
            s.push({h[i], w});
            r[i] = sum;
        }
        long long ans = 0;
        for (int i=0; i!=h.size(); i++) ans = max(ans, l[i] + r[i] - h[i]);
        return ans;
    }
};
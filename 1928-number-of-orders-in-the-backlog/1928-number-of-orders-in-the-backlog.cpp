class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& arr) {
        long long ans = 0, mod = 1000000007;
        priority_queue<pair<int, int>> s, b;
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i][2] == 0)
            {
                int count = arr[i][1], price = arr[i][0];
                while (count > 0 && s.size() > 0 && -s.top().first <= price)
                {
                    int c = s.top().second, p = -s.top().first;
                    s.pop();
                    if (c <= count) count -= c;
                    else
                    {
                        c -= count;
                        count = 0;
                        s.push({-p, c});
                    }
                }
                if (count > 0) b.push({price, count});
            }
            else
            {
                int count = arr[i][1], price = arr[i][0];
                while (count > 0 && b.size() > 0 && b.top().first >= price)
                {
                    int c = b.top().second, p = b.top().first;
                    b.pop();
                    if (c <= count) count -= c;
                    else
                    {
                        c -= count;
                        count = 0;
                        b.push({p, c});
                    }
                }
                if (count > 0) s.push({-price, count});
            }
        }
        while (s.size() > 0)
        {
            ans += s.top().second;
            s.pop();
        }
        while (b.size() > 0)
        {
            ans += b.top().second;
            b.pop();
        }
        return ans % mod;
    }
};
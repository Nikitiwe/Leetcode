class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& bb, vector<int>& s, vector<int>& t) {
        unordered_set<long> b;
        for (int i=0; i!=bb.size(); i++)
        {
            b.insert((long)1000000*bb[i][0] + bb[i][1]);
        }
        queue<pair<long, long>> q;
        q.push({s[0], s[1]});
        unordered_set<long> v;
        while (q.size() > 0)
        {
            long x = q.front().first;
            long y = q.front().second;
            q.pop();
            if (x == t[0] && y == t[1]) return 1;
            if (x > 0 && b.count(1000000*(x-1) + y) == 0 && v.count(1000000*(x-1) + y) == 0)
            {
                q.push({x-1, y});
                v.insert(1000000*(x-1) + y);
            }
            if (y > 0 && b.count(1000000*(x) + y-1) == 0 && v.count(1000000*(x) + y-1) == 0)
            {
                q.push({x, y-1});
                v.insert(1000000*(x) + y-1);
            }
            if (x+1 < 1000000 && b.count(1000000*(x+1) + y) == 0 && v.count(1000000*(x+1) + y) == 0)
            {
                q.push({x+1, y});
                v.insert(1000000*(x+1) + y);
            }
            if (y+1 < 1000000&& b.count(1000000*(x) + y+1) == 0 && v.count(1000000*(x) + y+1) == 0)
            {
                q.push({x, y+1});
                v.insert(1000000*(x) + y+1);
            }
            if (abs(x - s[0]) + abs(y-s[1]) > 400) break;
        }
        if (q.size() == 0) return 0;
        q = queue<pair<long, long>>();
        v.clear();
        q.push({t[0], t[1]});
        while (q.size() > 0)
        {
            long x = q.front().first;
            long y = q.front().second;
            q.pop();
            if (x > 0 && b.count(1000000*(x-1) + y) == 0 && v.count(1000000*(x-1) + y) == 0)
            {
                q.push({x-1, y});
                v.insert(1000000*(x-1) + y);
            }
            if (y > 0 && b.count(1000000*(x) + y-1) == 0 && v.count(1000000*(x) + y-1) == 0)
            {
                q.push({x, y-1});
                v.insert(1000000*(x) + y-1);
            }
            if (x+1 < 1000000 && b.count(1000000*(x+1) + y) == 0 && v.count(1000000*(x+1) + y) == 0)
            {
                q.push({x+1, y});
                v.insert(1000000*(x+1) + y);
            }
            if (y+1 < 1000000&& b.count(1000000*(x) + y+1) == 0 && v.count(1000000*(x) + y+1) == 0)
            {
                q.push({x, y+1});
                v.insert(1000000*(x) + y+1);
            }
            if (abs(x - s[0]) + abs(y-s[1]) > 400) break;
        }
        if (q.size() == 0) return 0;
        else return 1;
    }
};
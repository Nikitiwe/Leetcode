class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        for (int i=0; i!=q.size(); i++)
        {
            int x = q[i][0], y = q[i][1];
            if (x < y) swap(x, y);
            int l = 1;
            unordered_set<int> s;
            s.insert(x);
            s.insert(y);
            while (1)
            {
                if (x < y*2)
                {
                    x /= 2;
                    l++;
                    if (s.count(x) != 0) break;
                    s.insert(x);
                    y /= 2;
                    l++;
                    if (s.count(y) != 0) break;
                    s.insert(y);
                }
                else
                {
                    x /= 2;
                    l++;
                    if (s.count(x) != 0) break;
                    s.insert(x);
                }
            }
            ans.push_back(l);
        }
        return ans;
    }
};
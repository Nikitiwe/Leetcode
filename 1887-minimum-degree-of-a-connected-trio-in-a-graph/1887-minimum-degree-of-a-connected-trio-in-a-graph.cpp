class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& e) {
        int ans = 1000000;
        unordered_map<int, int> c;
        unordered_set<int> s;
        for (int i=0; i!=e.size(); i++)
        {
            s.insert(e[i][0]*1000 + e[i][1]);
            s.insert(e[i][1]*1000 + e[i][0]);
            c[e[i][1]]++;
            c[e[i][0]]++;
        }
        for (int i=0; i<=n; i++)
        {
            for (int j=i+1; j<=n; j++)
            {
                if (s.count(i*1000 + j) == 1) for (int k = j+1; k<=n; k++)
                {
                    if (s.count(i*1000 + k) == 1 && s.count(j*1000 + k) == 1)
                    {
                        ans = min(ans, c[i] + c[j] + c[k] - 6);
                    }
                }
            }
        }
        if (ans < 1000000) return ans;
        else return -1;
    }
};
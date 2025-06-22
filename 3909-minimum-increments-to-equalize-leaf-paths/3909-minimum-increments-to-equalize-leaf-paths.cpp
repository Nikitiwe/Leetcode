class Solution {
public:
    long f(int &ans, vector<vector<int>> &arr, vector<bool> &isit, vector<long> &c, int id)
    {
        isit[id] = 0;
        long sum = 0;
        int add = 0;
        int count = 0;
        for (int i=0; i<arr[id].size(); i++)
        {
            if (isit[arr[id][i]] == 1)
            {
                count++;
                long t = f(ans, arr, isit, c, arr[id][i]);
                if (t > sum)
                {
                    sum = t;
                    add = count - 1;
                }
                else if (t < sum)
                {
                    add++;
                }
            }
        }
        c[id] += sum;
        ans += add;
        return c[id];
    }

    int minIncrease(int n, vector<vector<int>>& e, vector<int>& cost) {
        vector<vector<int>> arr(n, vector<int>());
        vector<bool> isit(n, 1);
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back(e[i][1]);
            arr[e[i][1]].push_back(e[i][0]);
        }
        vector<long> c{cost.begin(), cost.end()};
        int ans = 0;
        f(ans, arr, isit, c, 0);
        return ans;
    }
};
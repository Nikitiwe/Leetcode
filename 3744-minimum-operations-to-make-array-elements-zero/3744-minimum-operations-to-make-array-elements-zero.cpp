class Solution {
public:
    long long f(int a)
    {
        long long res = 0;
        long long st = 1;
        while (a >= st)
        {
            res += a - st + 1;
            st *= 4;
        }
        return res;
    }

    long long minOperations(vector<vector<int>>& q) {
        long long ans = 0;
        for (int i=0; i!=q.size(); i++)
        {
            ans += (f(q[i][1]) - f(q[i][0] - 1) + 1)/2;
        }
        return ans;
    }
};
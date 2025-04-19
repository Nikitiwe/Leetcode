class Solution {
public:
    int f(vector<int>& m, vector<int>& h, int i)
    {
        if (h[m[i]] == -1) h[m[i]] = f(m, h, m[i]);
        return 1 + h[m[i]];
    }

    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& t) {
        vector<int> ans(n, 0), h(n, -1);
        h[headID] = 0;
        for (int i=0; i!=n; i++)
        {
            if (h[i] == -1)
            {
                h[i] = f(m, h, i);
            }
        }
        vector<vector<int>> arr(n, vector<int> (2, 0));
        for (int i=0; i!=n; i++)
        {
            arr[i][0] = h[i];
            arr[i][1] = i;
        }
        sort(arr.rbegin(), arr.rend());
        for (int i=0; i<arr.size()-1; i++)
        {
            ans[m[arr[i][1]]] = max(ans[m[arr[i][1]]], ans[arr[i][1]] + t[arr[i][1]]);
        }
        return ans[headID] + t[headID];
    }
};
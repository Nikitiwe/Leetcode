class Solution {
public:
    void f(vector<int> arr, int k, vector<vector<string>> &ans, int n)
    {
        if (k < arr.size()-1) for (int i=1; i<=n; i++)
        {
            bool isit = 1;
            for (int j=0; j<k; j++)
            {
                if (arr[j] == i || arr[j] + (k-j) == i || arr[j] - (k-j) == i)
                {
                    isit = 0;
                    break;
                }
            }
            if (isit == 1)
            {
                arr[k] = i;
                f(arr, k+1, ans, n);
            }
        }
        else for (int i=1; i<=n; i++)
        {
            bool isit = 1;
            for (int j=0; j<k; j++)
            {
                if (arr[j] == i || arr[j] + (k-j) == i || arr[j] - (k-j) == i)
                {
                    isit = 0;
                    break;
                }
            }
            if (isit == 1)
            {
                vector<string> tt;
                for (int j = 0; j<arr.size()-1; j++)
                {
                    string t;
                    for (int a = 1; a <= n; a++)
                    {
                        if (a == arr[j]) t += 'Q';
                        else t += '.';
                    }
                    tt.push_back(t);
                }
                string t;
                for (int a = 1; a <= n; a++)
                {
                     if (a == i) t += 'Q';
                    else t += '.';
                }
                tt.push_back(t);
                ans.push_back(tt);
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) return {{"Q"}};
        vector<vector<string>> ans;
        vector<int> arr(n, -1);
        for (int i=1; i<=n; i++)
        {
            arr[0] = i;
            f(arr, 1, ans, n);
        }
        return ans;
    }
};
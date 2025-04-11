class Solution {
public:
    void f(vector<int> arr, int k, int &ans, int n)
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
                ans++;
            }
        }
        return;
    }

    int totalNQueens(int n) {
        if (n == 1) return 1;
        int ans = 0;
        vector<int> arr(n, -1);
        for (int i=1; i<=n; i++)
        {
            arr[0] = i;
            f(arr, 1, ans, n);
        }
        return ans;
    }
};
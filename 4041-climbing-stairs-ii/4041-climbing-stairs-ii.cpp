class Solution {
public:
    int climbStairs(int n, vector<int>& c) {
        vector<int> arr(n+1, 2000000000);
        arr[0] = 0;
        for (int i=0; i<n; i++)
        {
            if (i+1 <= n) arr[i+1] = min(arr[i+1], arr[i] + c[i] + 1);
            if (i+2 <= n) arr[i+2] = min(arr[i+2], arr[i] + c[i+1] + 4);
            if (i+3 <= n) arr[i+3] = min(arr[i+3], arr[i] + c[i+2] + 9);
        }
        return arr[n];        
    }
};
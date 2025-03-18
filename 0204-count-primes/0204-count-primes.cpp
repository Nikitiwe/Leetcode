class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;
        vector<int> arr(n+1, 1);
        int ans = 0;
        for (int i=2; i<n; i++)
        {
            if (arr[i] == 1)
            {
                ans++;
                for (int j = 2*i; j<=n; j += i) arr[j] = 0;
            }
        }
        return ans;
    }
};
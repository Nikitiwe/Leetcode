class Solution {
public:
    int f (vector<int> &arr, int i, int add)
    {
        int t = 0;
        arr[i] += add;
        for (int j=0; j!=arr.size(); j++)
        {
            t *= 2;
            t += arr[j] % 2;
        }
        arr[i] -= add;
        return t;
    }

    long long wonderfulSubstrings(string s) {
        long long ans = 0;
        vector<int> c(1024, 0), arr(10, 0);
        c[f(arr, 0, 0)]++;
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i] - 'a']++;
            ans += c[f(arr, 0, 0)];
            for (int j = 0; j!=arr.size(); j++)
            {
                ans += c[f(arr, j, 1)];
            }
            c[f(arr, 0, 0)]++;
        }
        return ans;
    }
};
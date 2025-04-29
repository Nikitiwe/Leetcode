class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr(n, pair<int, int>());
        for (int i=0; i!=arr.size(); i++)
        {
            arr[i].first = efficiency[i];
            arr[i].second = speed[i];
        }
        sort(arr.rbegin(), arr.rend());
        priority_queue<int> q;
        long long sum = 0, mod = 1000000007, ans = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            if (q.size() < k)
            {
                q.push( - arr[i].second);
                sum += arr[i].second;
            }
            else
            {
                if (arr[i].second > - q.top())
                {
                    sum += q.top();
                    q.pop();
                    q.push( - arr[i].second);
                    sum += arr[i].second;
                }
            }
            ans = max(ans, sum * arr[i].first);
        }
        return ans % mod;
    }
};
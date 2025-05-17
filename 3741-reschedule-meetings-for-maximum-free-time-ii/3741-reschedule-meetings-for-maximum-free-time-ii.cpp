class Solution {
public:
    int maxFreeTime(int n, vector<int>& s, vector<int>& e) {
        if (s.size() == 1) return n - (e[0] - s[0]);
        vector<pair<int, int>> arr;
        int prev = 0;
        int ans = 0;
        for (int i=0; i!=s.size(); i++)
        {
            arr.push_back({s[i] - prev, i});
            prev = e[i];
        }
        arr.push_back({n - prev, s.size()});
        sort(arr.rbegin(), arr.rend());
        {
            if (arr[2].first >= e[0] - s[0])
            {
                ans = max(ans, s[1] - 0);
            }
            else if (arr[1].first >= e[0] - s[0] && arr[1].second != 0 && arr[1].second != 1)
            {
                ans = max(ans, s[1] - 0);
            }
            else if (arr[0].first >= e[0] - s[0] && arr[0].second != 0 && arr[0].second != 1)
            {
                ans = max(ans, s[1] - 0);
            }
            else
            {
                ans = max(ans, s[1] - 0 - (e[0] - s[0]));
            }
        }
        for (int i=1; i+1<s.size(); i++)
        {
            if (arr[2].first >= e[i] - s[i])
            {
                ans = max(ans, s[i+1] - e[i-1]);
            }
            else if (arr[1].first >= e[i] - s[i] && arr[1].second != i && arr[1].second != i+1)
            {
                ans = max(ans, s[i+1] - e[i-1]);
            }
            else if (arr[0].first >= e[i] - s[i] && arr[0].second != i && arr[0].second != i+1)
            {
                ans = max(ans, s[i+1] - e[i-1]);
            }
            else
            {
                ans = max(ans, s[i+1] - e[i-1] - (e[i] - s[i]));
            }
        }
        {
            int l = s.size()-1;
            if (arr[2].first >= e[l] - s[l])
            {
                ans = max(ans, n - e[l-1]);
            }
            else if (arr[1].first >= e[l] - s[l] && arr[1].second != l && arr[1].second != l+1)
            {
                ans = max(ans, n - e[l-1]);
            }
            else if (arr[0].first >= e[l] - s[l] && arr[0].second != l && arr[0].second != l+1)
            {
                ans = max(ans, n - e[l-1]);
            }
            else
            {
                ans = max(ans, n - e[l-1] - (e[l] - s[l]));
            }
        }
        return ans;
    }
};
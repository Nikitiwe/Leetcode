class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> q;
        int ans = 0, t = 0;
        vector<pair<int, int>> arr;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == '(') q.push({'(', i});
            else
            {
                if (q.size() > 0)
                {
                    int t = q.top().second;
                    q.pop();
                    while (arr.size() > 0)
                    {
                        int l = arr.back().first;
                        int r = arr.back().second;
                        if (l > t && r < i) arr.pop_back();
                        else break;
                    }
                    arr.push_back({t, i});
                }
            }
        }
        int prev = -1;
        int sum = 0;
        for (int i=0; i<arr.size(); i++)
        {
            if (i > 0)
            {
                if (prev + 1 == arr[i].first)
                {
                    sum += arr[i].second - arr[i].first + 1;
                    prev = arr[i].second;
                    ans = max(ans, sum);
                }
                else
                {
                    sum = arr[i].second - arr[i].first + 1;
                    ans = max(ans, sum);
                    prev = arr[i].second;
                }
            }
            else
            {
                sum = arr[i].second - arr[i].first + 1;
                ans = max(ans, sum);
                prev = arr[i].second;
            }
        }
        return ans;
    }
};
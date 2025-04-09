class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int a=1; a<=n; a++)
        {
            int k = a*a;
            string s = to_string(k);
            int l = s.size();
            vector<vector<pair<int, int>>> arr;
            arr.push_back({{0, s[0] - '0'}});
            for (int i=1; i<s.size(); i++)
            {
                arr.push_back({{100000, 100000}});
                for (int j=0; j!=arr[i-1].size(); j++)
                {
                    int sum = arr[i-1][j].first, last = arr[i-1][j].second;
                    if (sum + last*10 + s[i] - '0' <= a) arr[i].push_back({sum, last*10 + s[i] - '0'});
                    if (sum + last + s[i] - '0' <= a) arr[i].push_back({sum + last, s[i] - '0'});
                }
            }
            for (int j=0; j!=arr[l-1].size(); j++)
            {
                if ((arr[l-1][j].first + arr[l-1][j].second) == a)
                {
                    ans += k;
                    break;
                }
            }
        }
        return ans;
    }
};
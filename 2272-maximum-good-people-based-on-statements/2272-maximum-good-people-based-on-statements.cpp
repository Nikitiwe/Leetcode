class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        int ans = 0;
        int k = 1, a = s.size();
        while (a > 0)
        {
            k *= 2;
            a--;
        }
        for (int a = 0; a<k; a++)
        {
            int t = a;
            int count = 0;
            vector<int> arr(s.size(), 0);
            for (int i=0; i!=arr.size(); i++)
            {
                arr[i] = t%2;
                count += arr[i];
                t /= 2;
            }
            if (count > ans)
            {
                bool isit = 1;
                for (int i=0; i!=s.size(); i++)
                {
                    if (arr[i] == 1) for (int j=0; j!=s[0].size(); j++)
                    {
                        if (j != i && s[i][j] != 2 && (arr[j] != s[i][j] ) )
                        {
                            isit = 0;
                            break;
                        }
                    }
                    if (isit == 0) break;
                }
                if (isit == 1) ans = max(ans, count);
            }
        }
        return ans;
    }
};
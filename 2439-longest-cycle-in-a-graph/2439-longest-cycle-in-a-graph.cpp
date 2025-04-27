class Solution {
public:
    int longestCycle(vector<int>& e) {
        int ans = -1;
        vector<int> arr(e.size(), -1);
        for (int i=0; i!=e.size(); i++)
        {
            if (arr[i] == -1)
            {
                unordered_set<int> ids;
                int t = i;
                int l = 0;
                arr[t] = l;
                ids.insert(t);
                while (e[t] != -1 )
                {
                    t = e[t];
                    l++;
                    if (ids.count(t) != 0)
                    {
                        ans = max(ans, l - arr[t]);
                        break;
                    }
                    if (arr[t] != -1) break;
                    arr[t] = l;
                    ids.insert(t);
                }
            }
        }
        return ans;
    }
};
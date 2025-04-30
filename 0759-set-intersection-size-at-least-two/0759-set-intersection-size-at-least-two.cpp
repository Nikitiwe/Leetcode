bool ssort(const vector<int> &a, const vector<int> &b)
    {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

class Solution {
public:
    void add(vector<vector<int>>& arr, vector<int> &c, int x, int l, unordered_set<int> &h)
    {
        if (h.count(x) == 0)
        {
            h.insert(x);
            for (int i=l; i<arr.size(); i++)
            {
                if (x <= arr[i][1] && arr[i][0] <= x)
                {
                    c[i]++;
                }
            }
        }
    }

    int intersectionSizeTwo(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), ssort);
        int i = 0, ans = 0;
        vector<int> c(arr.size(), 0);
        unordered_set<int> h;
        while (i<arr.size())
        {
            if (c[i] == 0)
            {
                ans += 2;
                int t = 0;
                while (c[i] < 2)
                {
                    add(arr, c, arr[i][1]-t, i, h);
                    t++;
                }
            }
            else if (c[i] == 1)
            {
                ans++;
                int t = 0;
                while (c[i] < 2)
                {
                    add(arr, c, arr[i][1]-t, i, h);
                    t++;
                }
            }
            i++;
        }
        return ans;
    }
};
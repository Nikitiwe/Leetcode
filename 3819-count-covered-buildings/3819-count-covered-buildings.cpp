bool ssort(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        if (b.size() < 5) return 0;
        sort(b.begin(), b.end());
        unordered_map<long, int> m;
        for (int i=1; i+1<b.size(); i++)
        {
            if (b[i-1][0] == b[i][0] && b[i][0] == b[i+1][0]) m[(long)2000000*b[i][0] + b[i][1]]++;
        }
        sort(b.begin(), b.end(), ssort);
        for (int i=1; i+1<b.size(); i++)
        {
            if (b[i-1][1] == b[i][1] && b[i][1] == b[i+1][1]) m[(long)2000000*b[i][0] + b[i][1]]++;
        }
        int ans = 0;
        for (auto i = m.begin(); i!=m.end(); i++)
        {
            if (i->second == 2) ans++;
        }
        return ans;
    }
};
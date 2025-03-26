class Solution {
public:
    int largestValsFromLabels(vector<int>& v, vector<int>& l, int n, int lim) {
        vector<vector<int>> arr;
        for (int i=0; i!=v.size(); i++)
        {
            arr.push_back({v[i], l[i]});
        }
        sort(arr.rbegin(), arr.rend());
        int ans = 0, count = 0;
        unordered_map<int, int> m;
        for (int i=0; i!=arr.size(); i++)
        {
            if (m.count(arr[i][1]) == 0 || m[arr[i][1]] < lim)
            {
                ans += arr[i][0];
                m[arr[i][1]]++;
                count++;
            }
            if (count == n) break;
        }
        return ans;
    }
};
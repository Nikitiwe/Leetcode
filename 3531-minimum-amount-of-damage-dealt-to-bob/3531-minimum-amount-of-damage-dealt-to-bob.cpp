class Solution {
public:
    long long minDamage(int p, vector<int>& d, vector<int>& h) {
        long long tt = 0;
        for (int i=0; i!=h.size(); i++) tt += (h[i] + p - 1)/p;
        vector<pair<int, int>> arr(d.size(), pair<int, int>());
        for (int i=0; i!=h.size(); i++)
        {
            arr[i].first = d[i];
            arr[i].second = h[i];
        }
        //sort(arr.begin(), arr.end(), ssort);
        sort(arr.begin(), arr.end(), [p](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.first * ((b.second + p - 1)/p) < b.first * ((a.second + p - 1)/p) ;
        });
        long long ans = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            ans += tt * arr[i].first;
            tt -= (arr[i].second + p - 1)/p;
        }
        return ans;
    }
};
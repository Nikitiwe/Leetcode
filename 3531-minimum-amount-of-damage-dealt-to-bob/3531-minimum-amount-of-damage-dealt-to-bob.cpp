class Solution {
public:
    long long minDamage(int p, vector<int>& d, vector<int>& h) {
        long long tt = 0;
        for (int i=0; i!=h.size(); i++) tt += (h[i] + p - 1)/p;
        vector<vector<int>> arr(d.size(), vector<int>(2, 0));
        for (int i=0; i!=h.size(); i++)
        {
            arr[i][0] = d[i];
            arr[i][1] = h[i];
        }
        //sort(arr.begin(), arr.end(), ssort);
        sort(arr.begin(), arr.end(), [p](const vector<int>& a, const vector<int>& b)
        {
            return a[0] * ((b[1] + p - 1)/p) < b[0] * ((a[1] + p - 1)/p) ;
        });
        long long ans = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            ans += tt * arr[i][0];
            tt -= (arr[i][1] + p - 1)/p;
        }
        return ans;
    }
};
class Solution {
public:
    double new21Game(int n, int k, int mp) {
        vector<double> arr(k+mp, 0), add = arr;
        arr[0] = 1;
        for (int i=0; i<arr.size(); i++)
        {
            if (i>0 && i<k+mp)
            {
                add[i] += add[i-1];
                arr[i] += add[i];
            }
            double t = arr[i] / mp;
            if (i<k && i+1 < arr.size()) add[i+1] += t;
            if (i<k && i+mp+1 < arr.size()) add[i+mp+1] -= t;
        }
        double ans = 0;
        for (int i=k; i<=n && i<k+mp; i++) ans += arr[i];
        return ans;
    }
};
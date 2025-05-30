class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> l(arr.size(), 0), r(arr.size(), arr.size()-1);
        stack<int> s;
        for (int i=0; i!=arr.size(); i++)
        {
            while(s.size() > 0 && arr[s.top()] > arr[i]) s.pop();
            if (s.size() > 0) l[i] = s.top() + 1;
            //else l[i] = i;
            s.push(i);
        }
        while (s.size() > 0) s.pop();
        for (int i=arr.size()-1; i>=0; i--)
        {
            while(s.size() > 0 && arr[s.top()] >= arr[i]) s.pop();
            if (s.size() > 0) r[i] = s.top() - 1;
            //else r[i] = i;
            s.push(i);
        }
        long long ans = 0, mod = 1e9 + 7;
        for (int i=0; i!=arr.size(); i++)
        {
            long long t = (long long)arr[i] * (r[i] - i + 1) * (i - l[i] + 1);
            ans += t;
            ans %= mod;
        }
        return ans;
    }
};
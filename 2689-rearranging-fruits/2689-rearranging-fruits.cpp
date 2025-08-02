class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> m;
        int mi = a[0];
        for (int i=0; i!=a.size(); i++) m[a[i]]++;
        for (int i=0; i!=b.size(); i++) m[b[i]]--;
        vector<int> arr;
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            if (abs(it->second) % 2 == 1)
            {
                return -1;
            }
            mi = min(mi, it->first);
            for (int i=0; i<abs(it->second)/2; i++) arr.push_back(it->first);
        }
        mi *= 2;
        //if (arr.size() % 2 == 1) return -1;
        long long ans = 0;
        sort(arr.begin(), arr.end());
        for (int i=0; i<arr.size()/2; i++)
        {
            if (arr[i] < mi) ans += (long long)arr[i];
            else ans += mi;
        }
        return ans;
    }
}; // можно использовать мелкие для перестановок